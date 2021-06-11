import java.io.*;
import java.util.*;


public class test {
	public static void main(String[] args) throws Exception {
		File inputFile = new File("input.txt");
		Scanner sc = new Scanner(inputFile);
		PrintWriter pw = new PrintWriter(new
		                                 BufferedWriter(new FileWriter("output.txt")));

		int n = sc.nextInt();
		int m = sc.nextInt();

		int a[] = new int[n];
		int b[] = new int[m];
		for (int i = 0; i < n; i++)
			a[i] = sc.nextInt();
		for (int i = 0; i < m; i++)
			b[i] = sc.nextInt();


		int arr[][] = new int[n][m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				arr[i][j] = sc.nextInt();

		scn.close();
		pw.flush();

	}
}


// //created by astron98
// import java.io.*;
// import java.util.*;

// public class Main {

// 	public static void main(String[] args) throws Exception {
// 		// write your code here

// 		// BufferedReader Class for Fast buffer Input
// 		// BufferedReader br = new BufferedReader(
// 		//     new FileReader("input.txt"));

// 		//slow input
// 		File inputFile = new File("input.txt");
// 		Scanner sc = new Scanner(inputFile);

// 		// PrintWriter class prints formatted representations
// 		// of objects to a text-output stream.
// 		PrintWriter pw = new PrintWriter(new
// 		                                 BufferedWriter(new FileWriter("output.txt")));

// 		// Your code goes Here


// 		sc.close();
// 		pw.flush();
// 	}
// }

//method 3: for bufferedreader with input,output files
File inputFile = new File("../input.txt");
BufferedReader br = new BufferedReader(new FileReader(inputFile));
PrintWriter pw = new PrintWriter(new
                                 BufferedWriter(new FileWriter("output.txt")));