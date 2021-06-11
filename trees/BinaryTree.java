//created by astron98
import java.io.*;
import java.util.*;

class Node {
	int data;
	Node left, right;

	Node() {

	}
	Node(int data, Node l, Node r) {
		this.data = data;
		left = l;
		right = r;
	}
	Node(int data) {
		this.data = data;
		left = right = null;
	}
}

class Pair {
	Node node;
	int state;
	Pair() {}
	Pair(Node node, int state) {
		this.node = node;
		this.state = state;
	}
}

public class BinaryTree {
	// static final int mn = Integer.MIN_VALUE;
	public static Node construct(Integer[] arr) {
		if(arr.length==0)
			return null;

		Node root = new Node(arr[0]);
		Stack<Pair> st = new Stack<>();
		st.push(new Pair(root,1));
		int idx = 0;
		while(st.size()>0) {
			Pair top = st.peek();
			Integer currVal = null;
			if(top.state==1) {
				idx++;
				currVal = arr[idx];
				if(currVal!=null) {
					top.node.left = new Node(currVal);
					st.push(new Pair(top.node.left, 1));
				}
				
				top.state++;
			}
			else if(top.state==2) {
				idx++;
				currVal = arr[idx];
				if(currVal!=null) {
					top.node.right = new Node(currVal);
					st.push(new Pair(top.node.right, 1));
				}
				
				top.state++;
			}
			else {
				st.pop();
			}
		}

		return root;
	}

	public static void iterativePrePostInTraversal(Node node) {
    // write your code here
    if(node == null) return;
    Stack<Pair> st = new Stack<>();
    String pre="", in="", post="";
    st.push(new Pair(node, 1));
    
    while(st.size()>0) {
        Pair top = st.peek();
        if(top.state==1) {
            pre+=top.node.data + " ";
            if(top.node.left!=null) {
                st.push(new Pair(top.node.left, 1));
            }
            top.state++;
        }
        else if(top.state==2) {
            in += top.node.data + " ";
            if(top.node.right!=null) {
                st.push(new Pair(top.node.right, 1));
            }
            top.state++;
        }
        else {
            post += top.node.data + " ";
            st.pop();
        }
    }
    
    System.out.println(pre + "\n" + in +"\n"+post);
  }

	static class bstPair {
		boolean isBst;
		Node root=null;
		int size=0, min, max;
		bstPair() {

		}
	}

	public static bstPair largestSubBst(Node node) {
		
		if(node == null) {
			bstPair bp = new bstPair();
			bp.min = Integer.MAX_VALUE;
			bp.max = Integer.MIN_VALUE;
			bp.isBst = true;
			return bp;
		}

		bstPair lp = largestSubBst(node.left);
		bstPair rp = largestSubBst(node.right);
				
		bstPair mp = new bstPair();
		mp.isBst = lp.isBst && rp.isBst && (node.data > lp.max && node.data < rp.min);

		mp.min = Math.min(node.data, Math.min(lp.min, rp.min));
		mp.max = Math.max(node.data, Math.max(lp.max, rp.max));
		
		if(mp.isBst) {
			mp.root = node;
			mp.size = lp.size + rp.size + 1;
		}
		else if(lp.size > rp.size) {
			mp.root = lp.root;
			mp.size = lp.size;
		}
		else {
			mp.root = rp.root;
			mp.size = rp.size;
		}

		return mp;
	}

	public static void display(Node node) {
		if (node == null) {
			return;
		}

		String str = node.left == null ? "." : node.left.data + "";
		str += " <- " + node.data + " -> ";
		str += node.right == null ? "." : node.right.data + "";
		System.out.println(str);

		display(node.left);
		display(node.right);
	}

	public static void levelOrder(Node node) {
		Node root = node;
		if (root == null)
			return;

		Queue<Node> q = new ArrayDeque<>();

		q.add(root);
		while (q.size() > 0) {
			int queSize = q.size();

			for(int i=0;i<queSize; i++) {
				Node top = q.remove();
				System.out.print(top.data + " ");

				if (top.left != null)
					q.add(top.left);
				if (top.right != null)
					q.add(top.right);
			}
			System.out.println();
		}
	}

	public static Node createLeftCloneTree(Node node){
	    // write your code here
	    if(node == null) {
	        return null;
	    }
	    
	    Node l = createLeftCloneTree(node.left);
	    Node r = createLeftCloneTree(node.right);
	    Node tmp = new Node(node.data, null, null);
	    
	    /* cases:
	        0. both left n right nodes are null
	        1. only right node is null
	        2. only left node is null
	        3. both node exists
	    */
	    tmp.left = l;
	    node.left = tmp;
	    
	    return node;
	  }

	  public static Node transBackFromLeftClonedTree(Node node){
	    // write your code here
	    if(node == null) {
	        return null;
	    }
	    
	    if(node.left != null) {
	        node.left = node.left.left;
	    }
	    
	    transBackFromLeftClonedTree(node.left);
	    transBackFromLeftClonedTree(node.right);
	    return node;
	  }

	public static void main(String[] args) throws Exception {
		// write your code here


		File inputFile = new File("../../input.txt");
		Scanner sc = new Scanner(inputFile);

		// PrintWriter class prints formatted representations
		// of objects to a text-output stream.
		// PrintWriter pw = new PrintWriter(new
		                                 // BufferedWriter(new FileWriter("../../output.txt")));

		// Your code goes Here
		int n = sc.nextInt();
		Integer[] input = new Integer[n];
		sc.nextLine();
		String[] values = sc.nextLine().split(" ");
		for (int i = 0; i < n; i++) {
	      if (values[i].equals("n") == false) {
	        input[i] = Integer.parseInt(values[i]);
	      } else {
	        input[i] = null;
	      }
	    }

		// Integer input[] = {1, 2, 3, null, null, 4, null, null, null};
		Node root = construct(input);

		// display(root);
		// levelOrder(root);

		// largest subtree which is also a BST
		bstPair res = largestSubBst(root);
		System.out.println(res.root.data+"@"+res.size);

		//preorder, inorder, postorder in iterative
		// iterativePrePostInTraversal(root);

		sc.close();
		// pw.flush();
	}
}


/*
testcases:
1. largest subtree which is also a BST

inputs:
23
50 25 12 n n 37 30 n n 51 n n 75 62 60 n n 77 n n 87 n n

output:
25@5

*/


