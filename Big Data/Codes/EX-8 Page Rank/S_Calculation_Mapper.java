package bigdata;
import java.io.IOException;

import org.apache.hadoop.io.DoubleWritable;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;



public class S_Calculation_Mapper extends Mapper<LongWritable, Text, IntWritable, DoubleWritable >{
	

	@Override
	public void map(LongWritable key, Text value, Context context)
			throws IOException, InterruptedException {

	
		
		try
		{
			
				 
			String [] line= value.toString().split("\\s+");
			context.write(new IntWritable(1), new DoubleWritable(Double.valueOf(line[1])));
		}
		catch (Exception e)
		{
			
		}
		
	}

}
