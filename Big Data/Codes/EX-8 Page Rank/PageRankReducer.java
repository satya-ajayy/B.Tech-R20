package bigdata;
import java.io.IOException;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.io.DoubleWritable;
import org.apache.hadoop.io.ObjectWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Cluster;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Reducer;

public  class PageRankReducer extends Reducer<Text, ObjectWritable, Text, Text> {

	private long totalNodes;
	
	@Override
    public void setup(Context context) throws IOException, InterruptedException{
        Configuration conf = context.getConfiguration();
        Cluster cluster = new Cluster(conf);
        Job currentJob = cluster.getJob(context.getJobID());
     totalNodes =  currentJob.getCounters().findCounter(PageRankDriver.Counter.totalNodes).getValue();  
    
	}
	
	@Override
	protected void reduce(Text key, Iterable<ObjectWritable> values, Context context)
			throws IOException, InterruptedException {
		
	
		PageRank p= null;
	    double pageRankValue=0;
	    
	  
		for (ObjectWritable object: values)
		{
		
			if ( object.get() instanceof PageRank )
			{
				p= (PageRank) object.get(); //get the graph
				
			}
			
			else //otherwise the class is DoubleWritable
			{
				pageRankValue+=  PageRankDriver.BETA*( (DoubleWritable) object.get()).get(); //BETA=0.8
			}
		}
		
		pageRankValue+=  ( (1- context.getConfiguration().getDouble("sumOfPageRanks",-1))/totalNodes); //sumOfPageRanks is S which comes from the S_Calculation_Reducer (the other mapreduce job)
		
		p.setPageRankValue(pageRankValue);
		
		context.write(new Text(p.getNode()), new Text(p.toString()));
	
	}



}//end of Reduce class