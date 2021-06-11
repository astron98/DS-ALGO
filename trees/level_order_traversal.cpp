#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node{
	int data;
	struct node *left,*right;
};

void printLevelOrder(node *root){
	if(root==NULL)
		return;
	queue<node *> q;
	q.push(root);
	while(!q.empty()){
		node *curr = q.front();
		printf("%d ",curr->data);
		q.pop();
		if(curr->left !=NULL) q.push(curr->left);
		if(curr->right !=NULL) q.push(curr->right);
	}
}

node* newNode(int data){
	node *temp = new node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int main(){
	node* root = newNode(1);
	root->left = newNode(2);
	root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    printLevelOrder(root);
	return 0;
}
