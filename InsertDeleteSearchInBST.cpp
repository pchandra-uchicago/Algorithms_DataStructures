#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<algorithm>

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

Node* findMin(Node* root)
{
	if (root == NULL) return root;
	while (root->left != NULL)
	{
		root = root->left;
	}
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

bool search(Node* root, int data)
{
	if (root == NULL) return false;
	else if (root->data == data) return true;
	else if (data <= root->data) return search(root->left, data);
	else return search(root->right, data);
}

Node* deleteNode(Node* root, int data)
{
	if (root == NULL) return root;
	else if(data < root->data)
	{
		root->left = deleteNode(root->left, data);
	}
	else if (data > root->data)
	{
		root->right = deleteNode(root->right, data);
	}
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;			
		}
		else if(root->left == NULL || root->right == NULL)
		{
			Node* temp = root;
			if (root->left == NULL) root = root->right;
			else root = root->left;
			delete temp;			
		}
		else 
		{
			Node* temp = findMin(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
		}
	}
	return root;
}

int main()
{
	Node* root = NULL;
	root = Insert(root, 5);
	root = Insert(root, 4);
	root = Insert(root, 2);
	root = Insert(root, 7);
	root = Insert(root, 8);
	root = Insert(root, 6);
	root = deleteNode(root, 7);
	_getch();
	return 0;
}
