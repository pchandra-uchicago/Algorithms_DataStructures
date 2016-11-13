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
	else if (data <= root->data) {
		root->left = Insert(root->left, data);		
	}
	else {
		root->right = Insert(root->right, data);		
	}
	return root;
}

int hasPathSum(Node* A, int sum) {
	if (A== NULL || (sum - (A->data)) < 0) return 0;
	if ((A->left == NULL &&  A->right == NULL) && (sum - A->data == 0)) return 1;
	if ((A->left != NULL || A->right != NULL) && sum == 0) return 0;
	int remSum =sum - A->data;
	return hasPathSum(A->left, remSum) || hasPathSum(A->right, remSum);
}

int main()
{
	Node* root = NULL;
	root = Insert(root, 2);	
	root = Insert(root, 1);	
	root = Insert(root, 3);
	root = Insert(root, 5);
	root = Insert(root, 4);
	cout << "PathSum is :" << hasPathSum(root, 3);
	_getch();
}