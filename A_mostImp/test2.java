//author: astron98

import java.io.*;
import java.util.*;


public class test2 {
	public static precedence(char op) {
		switch(op) {
			case '*' || '/': {
				return 1;
				break;
			}
			case '+' || '-': {
				return 2;
				break;
			}
			default: {
				return 0;
				break;
			}
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader Class for Fast buffer Input
		BufferedReader br = new BufferedReader(new FileReader("input.txt"));

// 		//slow input
		// File inputFile = new File("input.txt");
		// Scanner sc = new Scanner(inputFile);
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));

		String exp = br.readLine();

		//code
		Stack<Integer> val = new Stack<>();
		Stack<Character> opr = new Stack<>();

		String a="", b="";
		int a1=0, b1=0;

		for(int i=0; i<exp.length(); i++) {
			char c = exp.charAt(i);
			if(Character.isDigit(c)) {
				val.push(c-'0');
			}
			else {
				if(opr.size()==0 || c=='(') {
					opr.push(c);
				}
				else {
					char top = opr.peek();
					int pTop = precedence(top);
					int pC = precedence(c);
					if(pTop >= pC) {
						b1 = val.pop();
						a1 = val.pop();

						
					}
					else {
						opr.push(c);
					}
				}
			}
		}

		scn.close();
		pw.flush();

	}
}

