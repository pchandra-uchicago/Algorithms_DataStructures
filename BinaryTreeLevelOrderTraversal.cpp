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

Node* Insert(Node* root, int data)
{
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

vector<char> levelOrderTraversal(Node* root)
{
	vector<char> result;
	if (root == NULL) return result;
	queue<Node*> q;
	q.push(root);
	
	/* while there is atleast one node in the queue*/
	while (!q.empty()) {
		Node* current = q.front();
		result.push_back(current->data);
		if (current->left != NULL)
			q.push(current->left);		
		if (current->right != NULL)
			q.push(current->right);
		q.pop();
	}
	return result;
}

int main()
{
	Node* root = NULL;
	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 30);
	vector<char> result = levelOrderTraversal(root);
	_getch();
	return 0;
}