// Created by ... astron98

/*

Binary Tree Maximum Path Sum between two leaf nodes.

Given a binary tree in which each node element contains a number. Find the maximum possible sum from one leaf node to another.
The maximum sum path may or may not go through root
*/
// Created by ... astron98

#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)

using namespace std;
using ll = long long;

struct Node {
	int data;
	Node *left, *right;
};

int maxPathSum(Node *root, int &res) {
	if(root == NULL)
		return 0;
		
	if(!root->left && !root->right)
		return root->data;

	int leftSum = maxPathSum(root->left, res);
	int rightSum = maxPathSum(root->right, res);
    
    if(root->left && root->right) {
    	res = max(res, root->data + leftSum + rightSum);
    	return root->data + max(leftSum, rightSum);
    }
    
    return (!root->left)? root->data + rightSum : root->data + leftSum;
}


Node* newNode(int data) {
	struct Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

Node* buildTree(Node* root, int i , int arr[], int &n) {
	if(i>=n) return root;

	if(arr[i] == INT_MIN)
		return root;

	Node* tempNode = newNode(arr[i]);
	root = tempNode;

	root->left = buildTree(root->left, 2*i + 1, arr, n);
	root->right = buildTree(root->right, 2*i + 2, arr, n); 

	return root;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Node* root = NULL;
	int n = 0;
	cin >> n;
	int arr[n];
	rep(i,n) {
		cin >> arr[i];
		//cout << "ith val:" << arr[i] << "\n";	//debug input values
	}

	root = buildTree(root, 0, arr, n);	//build the tree from arr[]
	int res = INT_MIN;
	maxPathSum(root, res);	// calculating the maxPathSum...	
    printf("max-path sum of the tree: %d\n", res);

    return 0;
}


/*

Logic:
-> since we cant start the count from any non-leaf nodes. 
	we need to exclude all those possibilities from check with "result" 
	where the path is being started at a non-leaf node.

	we do this by:
	if(root->left && root->right) {
    	res = max(res, root->data + leftSum + rightSum);
    	return root->data + max(leftSum, rightSum);
    }
    
    //we don't compare with "res" where the path is started from non-leaf node.
    return (!root->left)? root->data + rightSum : root->data + leftSum;
*/

/*
testcases:
case 1:
input:
4 -10 -1 0 3

output:
-8
--------------------

case 2:
input:
7
-10
9
20
INT_MIN
INT_MIN
15
7

output:
42
--------------------
*/