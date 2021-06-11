/*
1. check if a binary tree is a bst
*/

boolean isBST() {
	return isBSTUtil(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
}

boolean isBSTUtil(Node root, int mn, int mx) {
	if (root == null)
		return true;
	if (!(root.data > mn && root.data < mx))
		return false;
	return isBSTUtil(root.left, mn, root.data) && isBSTUtil(root.right, root.data, mx);
}

/*
2. Merge K sorted arrays
*/
import java.util.*;
import java.io.*;

class Item {
	int i, j;

	Item() {}
	Item(int i, int j) {
		this.i = i;
		this.j = j;
	}
}

public class Main {
	// int mx = Integer.MAX_VALUE;
	static void mergeKSortedArrays(int[][] arr, int n) {
		PriorityQueue<Item> q = new PriorityQueue<>();
		int i = 0;
		while (i < arr.length) {
			q.add(new Item(i, 0));
			i++;
		}

		while (q.size() > 0) {
			Item top = q.remove();
			int  j = top.j;
			i = top.i;
			if (i != -1)
				System.out.println(arr[i][j]);
			else
				continue;

			if (j + 1 < arr[i].length) {
				q.add(new Item(i, ++j));
			} else {
				q.peek().i = -1;
			}
		}
	}

	// Driver code
	public static void main(String args[]) {
		int[][] arr = {{2, 6, 12, 34},
			{1, 9, 20, 1000},
			{23, 34, 90, 2000}
		};

		mergeKSortedArrays(arr, arr.length);
	}
}


/*
3.
*/

/*
2.
*/

/*
2.
*/

/*
2.
*/

/*
2.
*/

/*
2.
*/

/*
2.
*/

