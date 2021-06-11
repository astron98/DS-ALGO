//author: astron98

import java.io.*;
import java.util.*;


public class HashMapMain {
	public static void main(String[] args) throws Exception {
		// BufferedReader Class for Fast buffer Input
		// BufferedReader br = new BufferedReader(new FileReader("input.txt"));

		// //slow input
		// File inputFile = new File("input.txt");
		// Scanner sc = new Scanner(inputFile);
		// PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));

		HashMap<String, Integer> hm = new HashMap<>();
		hm.put("India", 135);
		hm.put("China", 105);
		hm.put("Pak", 35);
		hm.put("US", 20);
		hm.put("UK", 10);

		//.containsKey()
		if(!hm.containsKey("Bangladesh"))
			System.out.println("not found");
		else
			System.out.println("found");

		System.out.println(hm);

		//.get()
		System.out.println(hm.get("India"));


		//.keySet()
		System.out.println("\n.keySet() usage:\n");
		Set<String> keys = hm.keySet();
		for(String key : keys) {
			System.out.println(key+" "+ hm.get(key));
		}

		// sc.close();
		// pw.flush();

	}
}
