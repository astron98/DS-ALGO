import java.io.*;
import java.util.*;

public class diameterOfTree {
	private static class Node {
		int data;
		ArrayList<Node> children = new ArrayList<>();
	}

	public static void display(Node node) {
		String str = node.data + " -> ";
		for (Node child : node.children) {
			str += child.data + ", ";
		}
		str += ".";
		System.out.println(str);

		for (Node child : node.children) {
			display(child);
		}
	}

	public static Node construct(int[] arr) {
		Node root = null;

		Stack<Node> st = new Stack<>();
		for (int i = 0; i < arr.length; i++) {
			if (arr[i] == -1) {
				st.pop();
			} else {
				Node t = new Node();
				t.data = arr[i];

				if (st.size() > 0) {
					st.peek().children.add(t);
				} else {
					root = t;
				}

				st.push(t);
			}
		}

		return root;
	}

	static int diameter = Integer.MIN_VALUE;
	public static int getDiameter(Node root) {
		if (root == null)
			return 0;

		int largestHeight = -1, secondLargestHeight = -1;
		for (int i = 0; i < root.children.size(); i++) {
			int currHeight = getDiameter(root.children.get(i));
			if (currHeight > largestHeight) {
				secondLargestHeight = largestHeight;
				largestHeight = currHeight;
			} else if (currHeight > secondLargestHeight) {
				secondLargestHeight = currHeight;
			}
		}

		/* add 2 cuz:
		(leftHeight + rightHeight + oneEdge-from-leftSubtreeToRoot
		 + oneEdge-from-rightSubtreeToRoot)
		to
		*/
		diameter = Math.max(diameter, largestHeight + secondLargestHeight + 2);

		return Math.max(largestHeight, secondLargestHeight) + 1;
	}

	public static void main(String[] args) throws Exception {
		File inputFile = new File("../input.txt");
		BufferedReader br = new BufferedReader(new FileReader(inputFile));
		PrintWriter pw = new PrintWriter(new
		                                 BufferedWriter(new FileWriter("output.txt")));
		int n = Integer.parseInt(br.readLine());
		int[] arr = new int[n];
		String[] values = br.readLine().split(" ");
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(values[i]);
		}

		Node root = construct(arr);
		// write your code here


		getDiameter(root);
		System.out.println(diameter);
	}

}


/*
1.
static int maxSumOFNode; static Node maxSumNode; public static int maxSubtreeSum(Node node){ } public static void main(String[] args) throws Exception { BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); int n = Integer.parseInt(br.readLine()); int[] arr = new int[n]; String[] values = br.readLine().split(" "); for (int i = 0; i < n; i++) { arr[i] = Integer.parseInt(values[i]); } Node root = construct(arr); maxSumOfNode = Integer.MIN_VALUE; maxSumNode = null; maxSubtreeSum(root); // returns sum of the tree System.out.println(maxSumNode.data+"@"+maxSumOFNode); }

2.
public static Node getTailNode(Node node){ while(node.children.size() > 0){ node = node.children.get(0); } return node; } public static void linearize(Node node){ for(Node child : node.children){ linearize(child); } while(node.children.size() > 1){ Node lc = node.children.remove(node.children.size()-1); Node slc = node.children.get(node.children.size()-1); Node tail = getTailNode(slc); tail.children.add(lc); } }

*/