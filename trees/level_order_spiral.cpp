//Note: solution is incomplete.
#include <bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	Node *left,*right;
};

//declaration of the functions.
void inorder(Node* root);
Node* newNode(int data);
void printSpiral(Node* root);

void printSpiral(struct Node* root){
	stack<Node*> s1,s2;
	
	s1.push(root);
	while(!s1.empty() || !s2.empty()) {
		
		while(!s1.empty()){
			Node* temp = s1.top();
			cout<< temp->data<<" ";
			s1.pop();
			if(temp->right) s2.push(temp->right);
			if(temp->left) s2.push(temp->left);
		}
		
		while(!s2.empty()){
			Node* temp = s2.top();
			cout<< temp->data<<" ";
			s2.pop();
			if(temp->left) s1.push(temp->left);
			if(temp->right) s1.push(temp->right);
		}
	}
}

Node* newNode(int data) {
	Node* temp = new Node();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
 
void inorder(Node* root){
	if(root==NULL) return;
	printf("%d ",root->data);
	inorder(root->left);
	inorder(root->right);
}
 
int main() {
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	printSpiral(root);
	
	return 0;
}
