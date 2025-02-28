package bigdata;
import java.io.IOException;

import org.apache.hadoop.io.DoubleWritable;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.mapreduce.Reducer;


public  class S_Calculation_Reducer extends Reducer<IntWritable, DoubleWritable, DoubleWritable, NullWritable> {

	

	@Override
	protected void reduce(IntWritable key, Iterable<DoubleWritable> values, Context context)
			throws IOException, InterruptedException {
		
		
		double s=0;
		for (DoubleWritable value: values)
		{
		     s+=value.get();
		     
			
		}
		
		context.write(new DoubleWritable(s), null);
		context.getCounter(PageRankDriver.Counter.sumOfPageRanks).setValue((long) s*10000);
	

	}
}//end of Reduce class