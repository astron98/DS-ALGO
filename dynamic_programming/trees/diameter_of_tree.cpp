// Created by ... astron98
/*
	Diameter of a tree:
	logic:	1. calculate the max-distance between 2 nodes at every node in the tree.
			2. Return the max of all these values.
*/
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


// to find the height of the tree (helper function)
int height(Node *root, int &res) {
	if(root == NULL)
		return 0;
	int leftHeight = height(root->left, res);
	int rightHeight = height(root->right, res);

	res = max(res, 1 + leftHeight + rightHeight);

	return 1 + max(leftHeight, rightHeight);
}


int diameter(Node* root) {
	if(root == NULL)
		return 0;

	int res = INT_MIN;
	height(root, res);

	return res;
}

Node* newNode(int data) {
	struct Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("../input.txt","r",stdin);
//     freopen("../output.txt","w",stdout);
// #endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 

    printf("Diameter of the tree: %d\n", diameter(root));

    return 0;
}


/*
testcases:
case 1:
input:


output:

--------------------
*/