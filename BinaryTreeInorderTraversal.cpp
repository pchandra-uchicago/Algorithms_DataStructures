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
	else if (data <= root->data)
		root->left = Insert(root->left, data);
	else
		root->right = Insert(root->right, data);
	return root;
}
vector<int> inOrderTraversal(Node* root) {
	vector<int> result;
	if (root == NULL) return result;
	inOrderTraversal(root->left);
	result.push_back(root->data);
	inOrderTraversal(root->right);
	return result;
}

int main()
{
	Node* root = NULL;
	Node* root = NULL;
	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 30);
	vector<int> result = inOrderTraversal(root);
	_getch();
	return 0;
}
