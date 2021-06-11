//author: astron98

import java.io.*;
import java.util.*;



public class bst {

	public static int leftMax(Node node) {
	    if(node.right!=null)
	        return leftMax(node.right);
	    return node.data;
	 }

	//remove a node from a BST
	public static Node remove(Node node, int data) {
		if(node == null)
		    return null;

		if(data < node.data)
		    node.left = remove(node.left, data);
		else if(data > node.data)
		    node.right = remove(node.right, data);
		else {
		    /*
		    4 cases:
		    no l, no r, no l-r, both l-r present.
		    */
		    if(node.left!=null && node.right!=null) {
		        int leftTreeMax = leftMax(node.left);
		        node.data = leftTreeMax;
		        node.left = remove(node.left, leftTreeMax);
		        return node;
		    }
		    else if(node.left!=null) {
		        return node.left;
		    }
		    else if(node.right !=null) {
		        return node.right;
		    }
		    else
		        return null;
		}

		return node;
	}


	/*	Description: print all nodes between d1 and d2

		You are required to complete the body of pir function. "pir" function is expected to print all nodes between d1 and d2 (inclusive and in increasing order).
	*/
	public static void pir(Node node, int d1, int d2) {
		// write your code here
		if(node == null)
		    return;

		if(d1<node.data && d2 < node.data)
		    pir(node.left, d1, d2);
		else if(d1>node.data && d2>node.data)
		    pir(node.right,d1, d2);
		else {
		    pir(node.left, d1, d2);
		    // if(node.data>=d1 && node.data<=d2) {
		        System.out.println(node.data);
		    // }
		    pir(node.right, d1, d2);
		}
	}

	public static void main(String[] args) throws Exception {
		// BufferedReader Class for Fast buffer Input
		// BufferedReader br = new BufferedReader(new FileReader("input.txt"));

		//slow input
		File inputFile = new File("input.txt");
		Scanner sc = new Scanner(inputFile);
		// PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));

		int n = sc.nextInt();
		int m = sc.nextInt();

		remove(node);

		scn.close();
	}
}
