#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

struct Node {
	Node* left; Node* right;
	int data;
};

Node* getNewNode(int data) {
	Node* root = new Node();
	root->data = data;
	root->left = root->right = NULL;
	return root;
}

Node* invertTree(Node* root) {
	if (root) {
		invertTree(root->left);
		invertTree(root->right);
		std::swap(root->left->data, root->right->data);
	}
	return root;
}

int main()
{
	Node* root = getNewNode(4);
	root->left = getNewNode(2);
	root->right = getNewNode(7);
	root->right->left = getNewNode(6);
	root->right->right = getNewNode(9);
	root->left->left = getNewNode(1);
	root->left->right = getNewNode(3);
	invertTree(root);
	_getch();
	return 0;
}