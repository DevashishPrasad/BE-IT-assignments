package demo;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Temp {

	public static void main(String args[]) throws Exception{
		String value = "user_id start_Time end_Time\n" + 
				"Devashish 9 10\n" + 
				"Kshitij 12 13\n" + 
				"Manish 3 7\n" + 
				"Ayan 0 1\n" + 
				"Devashish 1 2\n" + 
				"Manish 3 7\n" + 
				"kshitij 8 10\n" + 
				"Ayan 10 11";
		String text = value.toString();
		System.out.println(text);
		String[] lines = text.split("\n");
		int i =0;
		for(String line: lines){
			i++;
			if(i==1)
				continue;
			String[] words=line.split(" ");
		    String outputKey = new String(words[0].toUpperCase().trim());
			int datein = Integer.parseInt(words[1]);
			int dateout = Integer.parseInt(words[2]);
			long total = dateout - datein;
			int total_in = (int) total;
		    System.out.println(outputKey.toString() + total_in);
		}    
	}
}
