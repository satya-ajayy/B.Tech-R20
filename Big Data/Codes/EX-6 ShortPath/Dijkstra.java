package shortpath;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Iterator;
import org.apache.hadoop.fs.FileSystem;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.fs.s3.S3FileSystem;
import org.apache.hadoop.conf.*;
import org.apache.hadoop.io.*;
import org.apache.hadoop.mapreduce.*;
import org.apache.hadoop.mapreduce.lib.input.*;
import org.apache.hadoop.mapreduce.lib.output.*;
import org.apache.hadoop.util.*;

public class Dijkstra extends Configured implements Tool {

    public static String OUT = "outfile";
    public static String IN = "inputlarger";

    public static class TheMapper extends Mapper<LongWritable, Text, LongWritable, Text> {

        public void map(LongWritable key, Text value, Context context) throws IOException, InterruptedException {
            //From slide 20 of Graph Algorithms with MapReduce (by Jimmy Lin, Univ @ Maryland)
            //Key is node n
            //Value is D, Points-To
            //For every point (or key), look at everything it points to.
            //Emit or write to the points to variable with the current distance + 1
            Text word = new Text();
            String line = value.toString();//looks like 1 0 2:3:
            String[] sp = line.split(" ");//splits on space
            int distanceadd = Integer.parseInt(sp[1]) + 1;
            String[] PointsTo = sp[2].split(":");
            for(int i=0; i<PointsTo.length; i++){
                word.set("VALUE "+distanceadd);//tells me to look at distance value
                context.write(new LongWritable(Integer.parseInt(PointsTo[i])), word);
                word.clear();
            }
            //pass in current node's distance (if it is the lowest distance)
            word.set("VALUE "+sp[1]);
            context.write( new LongWritable( Integer.parseInt( sp[0] ) ), word );
            word.clear();

            word.set("NODES "+sp[2]);//tells me to append on the final tally
            context.write( new LongWritable( Integer.parseInt( sp[0] ) ), word );
            word.clear();

        }
    }

    public static class TheReducer extends Reducer<LongWritable, Text, LongWritable, Text> {
        public void reduce(LongWritable key, Iterable<Text> values, Context context) throws IOException, InterruptedException {
            //From slide 20 of Graph Algorithms with MapReduce (by Jimmy Lin, Univ @ Maryland)
            //The key is the current point
            //The values are all the possible distances to this point
            //we simply emit the point and the minimum distance value

            String nodes = "UNMODED";
            Text word = new Text();
            int lowest = 10009;//start at infinity

            for (Text val : values) {//looks like NODES/VALUES 1 0 2:3:, we need to use the first as a key
                String[] sp = val.toString().split(" ");//splits on space
                //look at first value
                if(sp[0].equalsIgnoreCase("NODES")){
                    nodes = null;
                    nodes = sp[1];
                }else if(sp[0].equalsIgnoreCase("VALUE")){
                    int distance = Integer.parseInt(sp[1]);
                    lowest = Math.min(distance, lowest);
                }
            }
            word.set(lowest+" "+nodes);
            context.write(key, word);
            word.clear();
        }
    }

    //Almost exactly from http://hadoop.apache.org/mapreduce/docs/current/mapred_tutorial.html
    public int run(String[] args) throws Exception {
        //http://code.google.com/p/joycrawler/source/browse/NetflixChallenge/src/org/niubility/learning/knn/KNNDriver.java?r=242
        getConf().set("mapred.textoutputformat.separator", " ");//make the key -> value space separated (for iterations)

        //set in and out to args.
        IN = args[0];
        OUT = args[1];

        String infile = IN;
        String outputfile = OUT + System.nanoTime();

        boolean isdone = false;
        boolean success = false;

        HashMap <Integer, Integer> _map = new HashMap<Integer, Integer>();

        while(isdone == false){

            Job job = new Job(getConf());
            job.setJarByClass(Dijkstra.class);
            job.setJobName("Dijkstra");
            job.setOutputKeyClass(LongWritable.class);
            job.setOutputValueClass(Text.class);
            job.setMapperClass(TheMapper.class);
            job.setReducerClass(TheReducer.class);
            job.setInputFormatClass(TextInputFormat.class);
            job.setOutputFormatClass(TextOutputFormat.class);

            FileInputFormat.addInputPath(job, new Path(infile));
            FileOutputFormat.setOutputPath(job, new Path(outputfile));

            success = job.waitForCompletion(true);

            //remove the input file
            //http://eclipse.sys-con.com/node/1287801/mobile
            if(infile != IN){
                String indir = infile.replace("part-r-00000", "");
                Path ddir = new Path(indir);
                //FileSystem dfs = FileSystem.get(getConf()); //Uncomment for local or hdfs
                FileSystem dfs = FileSystem.get(ddir.toUri(), getConf());
                dfs.delete(ddir, true);
            }

            infile = outputfile+"/part-r-00000";
            outputfile = OUT + System.nanoTime();

            //do we need to re-run the job with the new input file??
            //http://www.hadoop-blog.com/2010/11/how-to-read-file-from-hdfs-in-hadoop.html
            isdone = true;//set the job to NOT run again!
            Path ofile = new Path(infile);
            FileSystem fs = FileSystem.get(ofile.toUri(), new Configuration()); // For EMR
            //FileSystem fs = FileSystem.get(new Configuration()); //UnComment when run in local mode or using hdfs
            BufferedReader br=new BufferedReader(new InputStreamReader(fs.open(ofile)));

            HashMap<Integer, Integer> imap = new HashMap<Integer, Integer>();
            String line=br.readLine();
            while (line != null){
                //each line looks like 0 1 2:3:
                //we need to verify node -> distance doesn't change
                String[] sp = line.split(" ");
                int node = Integer.parseInt(sp[0]);
                int distance = Integer.parseInt(sp[1]);
                imap.put(node, distance);
                line=br.readLine();
            }
            if(_map.isEmpty()){
                //first iteration... must do a second iteration regardless!
                isdone = false;
            }else{
                //http://www.java-examples.com/iterate-through-values-java-hashmap-example
                //http://www.javabeat.net/articles/33-generics-in-java-50-1.html
                Iterator<Integer> itr = imap.keySet().iterator();
                while(itr.hasNext()){
                    int key = itr.next();
                    int val = imap.get(key);
                    if(_map.get(key) != val){
                        //values aren't the same... we aren't at convergence yet
                        isdone = false;
                    }
                }
            }
            if(isdone == false){
                _map.putAll(imap);//copy imap to _map for the next iteration (if required)
            }
        }

        return success ? 0 : 1;
    }

    public static void main(String[] args) throws Exception {
        System.exit(ToolRunner.run(new Dijkstra(), args));
    }
}

