// Java program for Flattening
// a linked list using Heaps
import java.util.*;

class Node {
	int data;
	Node down, right;

	Node(int data) {
		this.data = data;
		down = right = null;
	}
}

// comparator for Node-class
class NodeCompare implements Comparator<Node> {
	public int compare(Node a, Node b) {
		return a.data - b.data;
	}
}

public class flatten_linkedList {

	//flatten
	static Node flatten(Node head) {
		Node result = head;
		Node h = null;

		PriorityQueue<Node> pq = new PriorityQueue<>(new NodeCompare());


		//1. add all the node horizontally which has a downward linkedlist
		while (result != null) {
			pq.add(result);
			result = result.right;
		}

		//2.
		while (pq.size() > 0) {
			Node smallest = pq.remove();

			//push the next downward node pointed by the 'current' node to 'pq'
			if (smallest.down != null) {
				pq.add(smallest.down);
			}

			//create a new linkedList as a result
			if (h == null) {
				//if head is null, i.e. 'result'-linkedlist is empty
				h = smallest;
				result = smallest;
				result.right = null;
			} else {
				result.down = smallest;
				result = smallest;
				result.right = null;
			}
		}

		return h;	//return the 'head' node of the 'result' linkedlist
	}

	static Node push(Node headRef, int data) {
		Node newNode = new Node(data);
		newNode.down = headRef;
		headRef = newNode;

		return headRef;
	}

	static void printList(Node head) {
		// while (head != null) {
		while (head != null) {

			System.out.print(head.data + " ");
			head = head.down;
		}
		System.out.println();
	}

// Driver code
	public static void main(String args[]) {
		Node head = null;
		head = push(head, 30);
		head = push(head, 8);
		head = push(head, 7);
		head = push(head, 5);

		head.right = push(head.right, 20);
		head.right = push(head.right, 10);

		head.right.right = push(
		                       head.right.right, 50);
		head.right.right = push(
		                       head.right.right, 22);
		head.right.right = push(
		                       head.right.right, 19);

		head.right.right.right
		    = push(
		          head.right.right.right, 45);
		head.right.right.right
		    = push(
		          head.right.right.right, 40);
		head.right.right.right
		    = push(
		          head.right.right.right, 35);
		head.right.right.right
		    = push(head.right.right.right, 20);

		//flatten the linkedlist
		head = flatten(head);


		//print the linkedlist
		printList(head);
	}
}

