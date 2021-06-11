import java.io.*;
import java.util.*;

/*
	Description: Find all the target sum pairs in BST
	time: O(N), 
	Space: O(logN) - Space is propotional to the height of the tree cuz its BST. 

	/*	
		3 methods for the solution
		1. tspUtil
		2. inorder
		3. revInorder
	*/

public class targetSumPair_bst {
	static class Node {
		int data;
		Node left;
		Node right;

		Node(int data, Node left, Node right) {
		  this.data = data;
		  this.left = left;
		  this.right = right;
		}
	}

	static class Pair {
		Node node;
		int state;

		Pair(Node node, int state) {
		  this.node = node;
		  this.state = state;
		}
	}

	public static Node construct(Integer[] arr) {
		Node root = new Node(arr[0], null, null);
		Pair rtp = new Pair(root, 1);

		Stack<Pair> st = new Stack<>();
		st.push(rtp);

		int idx = 0;
		while (st.size() > 0) {
		  Pair top = st.peek();
		  if (top.state == 1) {
		    idx++;
		    if (arr[idx] != null) {
		      top.node.left = new Node(arr[idx], null, null);
		      Pair lp = new Pair(top.node.left, 1);
		      st.push(lp);
		    } else {
		      top.node.left = null;
		    }

		    top.state++;
		  } else if (top.state == 2) {
		    idx++;
		    if (arr[idx] != null) {
		      top.node.right = new Node(arr[idx], null, null);
		      Pair rp = new Pair(top.node.right, 1);
		      st.push(rp);
		    } else {
		      top.node.right = null;
		    }

		    top.state++;
		  } else {
		    st.pop();
		  }
		}

		return root;
	}

	public static void display(Node node) {
		if (node == null) {
		  return;
		}

		String str = "";
		str += node.left == null ? "." : node.left.data + "";
		str += " <- " + node.data + " -> ";
		str += node.right == null ? "." : node.right.data + "";
		System.out.println(str);

		display(node.left);
		display(node.right);
	}

	private static Node inorder(Stack<Pair> startStk) {
		while(startStk.size()>0) {
			Pair top = startStk.peek();
			if(top.state==1) {
				if(top.node.left!=null)
					startStk.push(new Pair(top.node.left, 1));
				top.state++;
			}
			else if(top.state==2) {
				if(top.node.right!=null)
					startStk.push(new Pair(top.node.right, 1));
				top.state++;
				return top.node;
			}
			else {
				startStk.pop();
			}
		}

		return null;
	}

	private static Node revInorder(Stack<Pair> endStk){
		while(endStk.size()>0){
			Pair top = endStk.peek();
			if(top.state==1){
				if(top.node.right!=null)
					endStk.push(new Pair(top.node.right, 1));
				top.state++;
			}
			else if(top.state==2) {
				if(top.node.left!=null)
					endStk.push(new Pair(top.node.left, 1));
				top.state++;
				return top.node;
			}
			else
				endStk.pop();
		}

		return null;
	}

	public static void tspUtil(Node node, int target) {
		if(node == null)
			return;
		
		Stack<Pair> endStk = new Stack<>();
		Stack<Pair> startStk = new Stack<>();

		startStk.push(new Pair(node, 1));
		endStk.push(new Pair(node, 1));

		Node startNode = inorder(startStk);	//retreive values in ascending order 
		Node endNode = revInorder(endStk);	//retreive values in descending order 
		while(startNode.data < endNode.data) {
			if(startNode.data+endNode.data==target) {
				System.out.println(startNode.data + " " + endNode.data);
				startNode = inorder(startStk);
				endNode = revInorder(endStk);
			} 
			else if(startNode.data + endNode.data < target)
				startNode = inorder(startStk);
			else
				endNode = revInorder(endStk);
		}
	}

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new FileReader("../input.txt"));
    int n = Integer.parseInt(br.readLine());
    Integer[] arr = new Integer[n];
    String[] values = br.readLine().split(" ");
    for (int i = 0; i < n; i++) {
      if (values[i].equals("n") == false) {
        arr[i] = Integer.parseInt(values[i]);
      } else {
        arr[i] = null;
      }
    }

    int data = Integer.parseInt(br.readLine());

    Node root = construct(arr);
    // write your code here
    tspUtil(root, data);

    br.close();
  }
}

// /home/astron/.config/sublime-text-3/Packages/User/java8.sublime-build
/*
//testcases
input:
21
50 25 12 n n 37 30 n n n 75 62 60 n n 70 n n 87 n n
100

output:
25 75
30 70
*/
