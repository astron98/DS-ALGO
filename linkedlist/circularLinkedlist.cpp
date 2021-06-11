/*
 * 	Circular singly Linkedlist
 *  Functions:
 * 		1. pushBack()
 * 		2. traverse();
 * */

#include<bits/stdc++.h>
using namespace std;

struct node {
	int data;
	node *next;
};

node* newNode(int val) {
	node* temp = new node;
	temp->data = val;
	temp->next = nullptr;
	return temp;
}

node* pushBack(node* head, int val) {
	node* temp = newNode(val);
	node* h = head;
	if (!head) {
		head = temp;
		head->next = head;
		return head;
	}
	else {
		while (h->next != head) {
			h = h->next;
		}
		h->next = temp;
		temp->next = head;
	}

	return head;
}

void traverse(node *head) {
	printf("Circular Linkedlist traversal:\n");
	node* h = head;
	if (!h) {
		cout << "the list is empty!\n";
		return;
	}

	cout << h->data << "->";
	h = h->next;

	while (h != head) {
		cout << h->data << "->";
		h = h->next;
	}
	printf("null\n");
}

int main() {
	node *head = nullptr;
	for (int i = 0; i < 7; i++) {
		head = pushBack(head, i + 1);
	}

	traverse(head);
	cout << '\n';
	return 0;
}
