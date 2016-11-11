#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<queue>
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
	else if (data <= root->data)
		root->left = Insert(root->left, data);
	else
		root->right = Insert(root->right, data);
	return root;
}


int minDepth(Node* root) {
	if (root == NULL) return 0;
	if (root->left == NULL)	return 1 + minDepth(root->right);
	if (root->right == NULL) return 1 + minDepth(root->left);
	return 1 + min(minDepth(root->left), minDepth(root->right));
}

int main()
{
	Node* root = NULL;
	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 30);
	cout << "Minimum depth of binary tree :" << minDepth(root);
	_getch();
	return 0;
}