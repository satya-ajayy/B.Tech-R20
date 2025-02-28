package bigdata;

import org.apache.hadoop.fs.FileSystem;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.DoubleWritable;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.io.ObjectWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.conf.Configured;
import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.util.Tool;
import org.apache.hadoop.util.ToolRunner;




public class PageRankDriver extends Configured implements Tool {

	public static double BETA=0.8;

	public static enum Counter {
		
		totalNodes,
		sumOfPageRanks;
	}
	
  @Override
  public int run(String[] args) throws Exception {


    if (args.length != 2) {
      System.out.printf("Usage: " + this.getClass().getName() + " <input dir> <output dir>\n");
      return -1;
    }
    
    int iterationCount=0;
   
   
    

while (true)
{
	 System.out.println("Running Map Reduce Job!!!!!!");

	 
	 
	 ///////////////////////////First Map Reduce Job Which calculates S///////////////////////////////////////

	    Job job_s = Job.getInstance(getConf());
	    job_s.setJarByClass(PageRankDriver.class);
	    job_s.setJobName("S_Calculation");
	    

	    FileSystem fs = FileSystem.get(new Configuration());
	   fs.delete(new Path("/Temp"), true);
	   fs.delete(new Path(args[1]), true);
	   
	    FileInputFormat.setInputPaths(job_s, new Path(args[0]));	    	
	    FileOutputFormat.setOutputPath(job_s, new Path("/Temp"));


	    
	    job_s.setReducerClass(S_Calculation_Reducer.class);
	    job_s.setMapperClass(S_Calculation_Mapper.class);

	 
		job_s.setMapOutputKeyClass(IntWritable.class);
		job_s.setMapOutputValueClass(DoubleWritable.class);
	    
		/*
		 * Set the key output class for the job_s
		 */   
	    job_s.setOutputKeyClass(DoubleWritable.class);
	    
	    /*
	     * Set the value output class for the job_s
	     */
	    job_s.setOutputValueClass(NullWritable.class);
	    job_s.setNumReduceTasks(1);
	    job_s.waitForCompletion(true); //the first job calculates S.
	
	  double sumOfPageRanks= (double) job_s.getCounters().findCounter(Counter.sumOfPageRanks).getValue()/ (double)10000.0; //getting sum of page ranks S from the previous job
	   System.out.println("S: "+sumOfPageRanks);
	   
	   
	    fs.delete(new Path("/Temp"),true);

   	    /////////////////////////Second map reduce job which calculates page rank of each node////////////////////////////////////////////////
	 Job job = Job.getInstance(getConf());
	    job.setJarByClass(PageRankDriver.class);
	    //job.setJobName("Page Rank");
	    job.getConfiguration().setDouble("sumOfPageRanks", sumOfPageRanks); //passing sum of Page ranks S.
	    


	    FileInputFormat.setInputPaths(job, new Path(args[0]));
	    	
	    
	    FileOutputFormat.setOutputPath(job, new Path(args[1]));


	    
	    job.setReducerClass(PageRankReducer.class);
	    job.setMapperClass(PageRankMapper.class);

	 
		job.setMapOutputKeyClass(Text.class);
		job.setMapOutputValueClass(ObjectWritable.class);
	    
		/*
		 * Set the key output class for the job
		 */   
	    job.setOutputKeyClass(Text.class);
	    
	    /*
	     * Set the value output class for the job
	     */
	    job.setOutputValueClass(Text.class);
	
	    
    boolean success = job.waitForCompletion(true);
  
    
    iterationCount++;
    
    
    if (iterationCount>2)
    {
    	
  
    	fs.delete(new Path(args[0]), true); //deleting folder before exiting
     
   	 System.out.println("Total Number of Times the Job was run= "+iterationCount);
    	System.out.println("total Nodes Processed: "+job.getCounters().findCounter(Counter.totalNodes).getValue());
     
   	    return (success==true ? 1: 0);
    }
    
    else
    {
       
    	fs.delete(new Path(args[0]), true);
    	
	 
    	fs.rename(new Path(args[1]), new Path(args[0]));
	 }
  
  }

  }
  
  
  public static void main(String[] args) throws Exception {
    int exitCode = ToolRunner.run(new Configuration(), new PageRankDriver(), args);
    System.exit(exitCode);
  }
  
   
}




