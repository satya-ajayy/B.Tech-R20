package bigdata;


import java.io.IOException;


import org.apache.hadoop.io.DoubleWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.ObjectWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

public class PageRankMapper extends Mapper<LongWritable, Text, Text,ObjectWritable> {

	

	@Override
	public void map(LongWritable key, Text value, Context context)
			throws IOException, InterruptedException {

	
		
		try
		{
				 
			PageRank pageRank=new PageRank(value);
		
			context.write(new Text(pageRank.getNode()), new ObjectWritable( pageRank));
            context.getCounter(PageRankDriver.Counter.totalNodes).increment(1);
            
			double pageRankValue= pageRank.getPageRankValue();
			double pageRankValueGivenToEachLink = pageRankValue/pageRank.getLinks().size();
			
			for (int i=0; i< pageRank.getLinks().size(); i++)
			{
				context.write(new Text(pageRank.getLinks().get(i)), new ObjectWritable(new DoubleWritable(pageRankValueGivenToEachLink)));
			}
			
		}
		catch (Exception e)
		{
			
		}
		
	}
}