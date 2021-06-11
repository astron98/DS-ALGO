#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *next;
};

void insertNode(node **head,int x){
	node *temp=new node;	
	/*	
	 * 	always allocate the memory to the struct or any pointer variable (as shown on line 10) 
	 *	before inserting any values else it will return a SEGMENTATION FAULT.	
	*/   
	node *tail = NULL;
	
	temp->data = x;
	temp->next = NULL;
	
	if(*head == NULL){
		*head = temp;
		return;
	}
	else{
		tail = *head;
		while(tail->next!=NULL){
			tail = tail->next;
		}
		
		tail->next = temp;
		return;
	}
}

void display(node *temp1){
	printf("printing the linkedlist. \n");
	//node *temp1 = head;
	while(temp1!=NULL){
		printf("%d ",temp1->data);
		temp1 = temp1->next;
	}
	printf("\n");
}
int main(){
	node *head=NULL;
	insertNode(&head,1);
	insertNode(&head,2);
	display(head);
	
	return 0;
}

