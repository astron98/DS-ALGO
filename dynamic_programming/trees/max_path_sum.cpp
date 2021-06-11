// Created by ... astron98

/*

124. Binary Tree Maximum Path Sum (Hard) [leetcode]

Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any node sequence from some starting node to any node in the tree
along the parent-child connections. The path must contain at least one node and does not need to go
through the root.

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

	int leftSum = max(maxPathSum(root->left, res), 0);
	int rightSum = max(maxPathSum(root->right, res), 0);

	res = max(res, root->data + leftSum + rightSum);

	return root->data + max(leftSum, rightSum);
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
testcases:
case 1:
input:


output:

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

--------------------
*/