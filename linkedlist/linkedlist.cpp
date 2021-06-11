#include<iostream>
//#include<>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

class linkedlist
{
		
	Node *head,*tail;
	public:
		//Note: Never use inbuild keywords in c++
		//function declaration for insert() and deleteNode().
		void insert(int n);
		void deleteNode(int k);
		linkedlist()
		{
			head = NULL;
			tail = NULL;
		}
		void print()
		{
			Node *temp =head;
			while(temp!=NULL)
			{
				printf("%d->",temp->data);
				temp =temp->next;
			}
			
			printf("\n");
		}
};

void linkedlist::insert(int n)
		{
			
			Node *temp = new Node;
			temp->data = n;
			
			if(head == NULL)
			{
				head = temp;
				tail = temp;
			}
			else 
			{
				printf("current head: %d \n",head->data);
				printf("current tail: %d \n",tail->data);
				tail->next = temp;
				tail = temp;
			}
		}

/*
 * 1. run a while loop till you find the key the node which need to be deleted.
 * 2. remove the node, by linking the previous of that node to the next of that particular Node which need to 
 * 	  be deleted.
* */
void linkedlist::deleteNode(int k)
{
	Node *temp = head;
	
	if(temp->next!=tail)
	{
		while((temp->next)->data != k)
		{
			temp = temp->next;
		}
		if(temp->next->next==NULL)
		{
			temp->next = NULL;
			tail = temp;
		}
		else
			temp->next = temp->next->next;
	}
	else 
	{
		/*
			 * if the deletinng element is the last Node, 
			 * then just make it null and change the tail to the last second.
			 * */
			if(temp->next ==tail && tail->data==k)   
			{
				temp->next = NULL;
				tail = temp;
			}
			
	}
}


int main()
 {
	
	linkedlist l;
	l.insert(1);
	l.insert(2);
	l.insert(4);
	
	l.deleteNode(4);
	l.print();
	
	l.insert(7);
	l.insert(9);
	
	l.print();
	return 0;
}
