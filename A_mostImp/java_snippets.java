d// fill the array
int[] visited = new int[vtces];
Arrays.fill(visited, -1);


//sort
Collections.sort(visited);	// for collections
Arrays.sort(visited);

//string to int
String sval = "2351";
int ival = Integer.parseInt(sval);


import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws Exception {
		// write your code here
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a[] = new int[n];

		for (int i = 0; i < n; i++)
			a[i] = sc.nextInt();

		int m = sc.nextInt();
		int b[] = new int[m];

		for (int i = 0; i < m; i++)
			b[i] = sc.nextInt();


	}

}

