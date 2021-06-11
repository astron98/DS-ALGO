#include<bits/stdc++.h>

using namespace std;

class node{
public:
	int data;
	node *prev;
	node *next;
	
	node();
};

node::node(){
	data = 0;
	prev = NULL;
	next = NULL;
}

void push(node **head,int x){
	node *temp = new node();
	temp->data = x;
	if(*head==NULL){
		*head = temp;
		return; 
	}
	else{
		node *tail = *head;
		while(tail->next!=NULL)
			tail = tail->next;
		tail->next = temp;
		temp->prev = tail;
		return;	
	}
}

// Display the Doubly-Linkedlist.
void display(node *head){
	printf("displaying the doubly-linkedlist: \n");
	while(head!=NULL){
		printf("%d ",head->data);
		head = head->next;
	}
	printf("\n");
}

int main()
{
	node *head = NULL;
	push(&head,2);
	
	display(head);
	
	return 0;
}
