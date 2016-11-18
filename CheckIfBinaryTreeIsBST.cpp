#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<algorithm>

using namespace std;
struct Node {
	Node* left;
	Node* right;
	int data;
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

bool search(Node* root, int data) {
	if (root == NULL) return false;
	else if (root->data == data) return true;
	else if (data <= root->data) return search(root->left, data);
	else return search(root->right, data);
}

bool isBSTUtil(Node* root, int minVal, int maxVal) {
	if (root == NULL) return true;
	if (root->data > minVal && root->data < maxVal
		&& isBSTUtil(root->left, minVal, root->data)
		&& isBSTUtil(root->right, root->data, maxVal))
		return true;
	else false;
}

bool isBinarySearchTree(Node* root) {
	return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main()
{
	Node* root = NULL;
	root = Insert(root, 5);
	root = Insert(root, 4);
	root = Insert(root, 2);
	root = Insert(root, 6);
	root = Insert(root, 7);
	bool result = isBinarySearchTree(root);
	_getch();
	return 0;
}
