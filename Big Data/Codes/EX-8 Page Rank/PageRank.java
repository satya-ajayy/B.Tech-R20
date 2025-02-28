package bigdata;
import java.io.DataInput;
import java.io.DataOutput;
import java.io.EOFException;
import java.io.IOException;
import java.util.ArrayList;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.io.Writable;

public class PageRank  implements Writable {

	String node;
	double pageRankValue;
	ArrayList<String> links; //links array stores the nodes that the node points to 
	
	PageRank()
	{
		
	}
	
	PageRank(Text value)
	{
        String []line= value.toString().split("\\s+");
        		
        this.node= line[0];
        this.pageRankValue= Double.valueOf(line[1]);
        links=new ArrayList<String>();
        
        
        for (int i=2; i< line.length; i++)
        {
        	  this.links.add((line[i]));
        	  
        }
      
	}

	ArrayList<String>  getLinks()  
	{
		return this.links;
	}
	
	String getNode()
	{
		return this.node;
	}
	
	double getPageRankValue()
	{
		return this.pageRankValue;
	}
	
	void setPageRankValue(double value)
	{
		this.pageRankValue=value;
	}
	
	@Override
	public String toString() {
		
		StringBuilder resultantString= new StringBuilder();
		
		
		resultantString.append(String.format("%.3f", pageRankValue));
		resultantString.append("   "); 
	
	   	
	 for (int i=0; i< links.size(); i++)
	 {
		resultantString.append(links.get(i));
		
		if (i<links.size()-1)
		{
			resultantString.append(" ");
		}
		
	 }
		
	return resultantString.toString();
  }//end of toString method

	@Override
	public void readFields(DataInput DataInput) throws IOException {
		// TODO Auto-generated method stub
		this.node=DataInput.readUTF();
		this.pageRankValue= DataInput.readDouble();
		this.links=new ArrayList<String>();
		
		try
		{
		   while (true)
		   {
			   String next=DataInput.readUTF();
			   this.links.add(next);
		   }
		
	    }
		catch(EOFException e)
		{  
			
		}
	}

	@Override
	public void write(DataOutput dataOutput) throws IOException {
		dataOutput.writeUTF(node);
		dataOutput.writeDouble(pageRankValue);
		
		for (int i=0; i<this.links.size(); i++)
		dataOutput.writeUTF(this.links.get(i));
		
	}
	
	
}
