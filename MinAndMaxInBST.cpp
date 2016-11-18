#include<iostream>
#include<conio.h>
#include<stdio.h>

using namespace std;

struct Node
{
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

int findMin(Node* root)
{	
	if (root == NULL) return -1;
	while (root->left != NULL) root = root->left;
	return root->data;
}

int findMinRecursion(Node* root)
{
	if (root == NULL) return -1;
	else if (root->left == NULL) return root->data;
	else return findMinRecursion(root->left);	
}

int findMax(Node* root)
{
	if (root == NULL) return -1;
	while (root->right != NULL)	root = root->right;
	return root->data;
}

int main()
{
	Node* root = NULL;
	root = Insert(root, 5);
	root = Insert(root, 6);
	root = Insert(root, 2);
	root = Insert(root, 3);
	int min = findMin(root);
	_getch();
	return 0;
}