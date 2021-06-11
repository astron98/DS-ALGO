//created by astron98
import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws Exception {
		// write your code here

		// BufferedReader Class for Fast buffer Input
		// BufferedReader br = new BufferedReader(
		//     new FileReader("input.txt"));

		//slow input
		File inputFile = new File("input.txt");
		Scanner sc = new Scanner(inputFile);

		// PrintWriter class prints formatted representations
		// of objects to a text-output stream.
		PrintWriter pw = new PrintWriter(new
		                                 Buffere`Writer(new FileWriter("output.txt")));

		// Your code goes Here
		//int res = sc.nextInt();

		//print output
		//pw.println(res);

		sc.close();
		pw.flush();
	}
}
