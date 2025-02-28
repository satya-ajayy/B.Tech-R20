package bda;

import java.io.IOException;
import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.*;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.util.GenericOptionsParser;
import java.util.*;
public class MutualFriends{

	public static class Map 
			extends Mapper<LongWritable, Text, Text, Text>{
		Text user = new Text();
		Text friends = new Text();
		
		public void map(LongWritable key, Text value, Context context)
				throws IOException, InterruptedException{
			/*Splitting each line into user and corresponding frien.d list*/
			String[] split=value.toString().split("\t");
			/*split[0] is user and split[1] is friend list */
			String userId=split[0];
			if(split.length==1) {
				return;
			}
			String[] friendIds=split[1].split(",");
			for(String friend : friendIds) {
				if(userId.equals(friend)) {
					continue;
				}
			String userKey = (Integer.parseInt(userId) < Integer.parseInt(friend))?userId + "," +friend : friend + ","+ userId;
			String regex="((\\b"+ friend + "[^\\w]+)|\\b,?" + friend + "$)";
			friends.set(split[1].replaceAll(regex, ""));
			user.set(userKey);
			context.write(user,friends);
			}
		}
	}
		
	public static class Reduce
			extends Reducer<Text, Text, Text, Text>{
		
		private String matchingFriends(String firstList, String secondList) {
			
			if(firstList == null || secondList == null) {
				return null;
			}
			
			String[] list1=firstList.split(",");
			String[] list2=secondList.split(",");
			
			LinkedHashSet<String> firstSet = new LinkedHashSet<String>();
			for(String  user: list1) {
				firstSet.add(user);
			}
			/*Retaining sort order*/
			LinkedHashSet<String> secondSet = new LinkedHashSet<String>();
			for(String  user: list2) {
				secondSet.add(user);
			}
			firstSet.retainAll(secondSet);
			/*Keeping only the matched friends*/
			return firstSet.toString().replaceAll("\\[|\\]", "");
		}
		
		public void reduce(Text key, Iterable<Text> values, Context context)
			throws IOException,InterruptedException{
			
			String[] friendsList = new String[2];
			int index=0;
			
			for(Text value:values) {
				friendsList[index++] = value.toString();
			}
			String mutualFriends = matchingFriends(friendsList[0],friendsList[1]);
			if(mutualFriends != null && mutualFriends.length() != 0) {
				context.write(key, new Text(mutualFriends));
			}
		}
		
	}

	


	// Driver program
	public static void main(String[] args) throws Exception {
		Configuration conf = new Configuration();
		String[] otherArgs = new GenericOptionsParser(conf, args).getRemainingArgs();
		// get all args
		if (otherArgs.length != 2) {
			System.err.println("Usage: MutualFriends <input file name> <output file name>");
			System.exit(2);
		}

		// create a job with name "mutual friends"
		@SuppressWarnings("deprecation")
		Job job = new Job(conf, "mutualfriends");
		job.setJarByClass(MutualFriends.class);
		job.setMapperClass(Map.class);
		job.setReducerClass(Reduce.class);


		// uncomment the following line to add the Combiner job.setCombinerClass(Reduce.class);


		// set output key type
		job.setOutputKeyClass(Text.class);
		// set output value type
		job.setOutputValueClass(Text.class);
		//set the HDFS path of the input data
		FileInputFormat.addInputPath(job, new Path(otherArgs[0]));
		// set the HDFS path for the output
		FileOutputFormat.setOutputPath(job, new Path(otherArgs[1]));
		//Wait till job completion
		System.exit(job.waitForCompletion(true) ? 0 : 1);
	}
}