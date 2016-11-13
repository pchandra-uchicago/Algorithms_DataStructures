#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;
struct Node {
	char data;
	Node* left;
	Node* right;
};

Node* getNewNode(int data) {
	Node* root = new Node();
	root->left = NULL;
	root->right = NULL;
	root->data = data;
	return root;
}

Node* Insert(Node* root, int data) {
	if (root == NULL) {
		root = getNewNode(data);
		return root;
	}
	else if (data <= root->data) {
		root->left = Insert(root->left, data);
	}
	else {
		root->right = Insert(root->right, data);
	}
	return root;
}

int computeHeight(Node* root, bool &flag) {
	if (root == NULL) return -1;
	if (root->left == NULL && root->right == NULL)
		return 1;

	int lheight = 0, rheight = 0;
	if (root->left != NULL) lheight = computeHeight(root->left, flag);
	else lheight = -1;

	if (root->right != NULL) rheight = computeHeight(root->right, flag);
	else rheight = -1;

	if (abs(lheight - rheight) > 1) flag = true;	
}

int isBalanced(Node* A) {
	bool flag = false;
	computeHeight(A, flag);
	if(flag) return 0;
	else return 1;
}

int main()
{
	Node* root = NULL;
	root = Insert(root, 1);
	root = Insert(root, 0);
	root = Insert(root, 4);
	root = Insert(root, 3);
	root = Insert(root, 2);
	isBalanced(root);
	return 0;
}
