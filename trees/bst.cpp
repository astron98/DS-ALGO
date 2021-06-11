#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *left,*right;
};

Node* newNode(int data);
Node* insert(Node* root,int data);
void inorder(Node* root);

Node* insert(Node* root,int data){
	
	if(root==NULL){
		Node* tmp = newNode(data);
		root = tmp;
		return root;
	}
	else {
		if(data <= root->data) 
			root->left = insert(root->left,data);
		else
			root->right = insert(root->right,data);
	}
	
	return root;
}

Node* deleteNode(Node* root,int data){
	if(root==NULL) return NULL;
	else if(data < root->data) root->left = deleteNode(root->left,data);
	else if(data > root->data) root->right = deleteNode(root->right,data);
	else {
		if(root->left==nullptr && root->right==nullptr){
			free(root);
			root = NULL;
		}
		else if(root->left == nullptr){
			Node* tmp = root;
			root = root->right;
			free(tmp);
		}
		else if(root->right == nullptr) {
			Node* tmp = root;
			root = root->left;
			free(tmp);
		}
		else {
			Node* temp = root->right;
			while(temp->left != NULL) temp = temp->left;
			
			root->data = temp->data;
			root->right = deleteNode(root->right,temp->data);
		}
	}
	return root;
}

void inorder(Node* root){
	if(root==NULL) return;
	printf("%d ",root->data);
	inorder(root->left);
	inorder(root->right);
}

Node* newNode(int data){
	Node* temp = new Node();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	
	return temp;
}

int main()
 {
	int arr[] = {5,2,3,7,8,6};
	Node* root = NULL;
	for(int i:arr){
		root = insert(root,i);
		printf("root value: %d\n",root->data);
	}
	inorder(root);
	printf("\n");
	deleteNode(root,8);
	inorder(root);
	printf("\n");
	return 0;
}
