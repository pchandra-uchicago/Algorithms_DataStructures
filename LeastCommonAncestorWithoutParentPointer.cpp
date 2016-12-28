#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<vector>
#include<algorithm>

using namespace std;

struct Node {
	Node * left; Node* right;
	int data;
};

Node* getNewNode(int data)
{
	Node* root = new Node();
	root->data = data;
	root->left = root->right = NULL;
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

void search(Node* root, Node* p, vector<Node*> &path)
{
	if (root == NULL) return;
	if (p->data == root->data) {
		path.push_back(root);
		return;
	}		
	else if (p->data < root->data) {
		path.push_back(root);
		search(root->left, p, path);
		return;
	}
	else {
		path.push_back(root);
		search(root->right, p, path);
		return;
	}		
}

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
	vector<Node*> path1; vector<Node*> path2; 
	search(root, p, path1);
	search(root, q, path2); int i;
	for ( i = 0; i < path1.size() && i < path2.size(); i++) {
		if (path1[i] != path2[i])
			break;
	}
	return path1[i-1] ;
}

int main()
{
	Node* root = getNewNode(6);
	root->left = getNewNode(2);
	Node* p = root->left;
	root->right = getNewNode(8);	
	root->right->left = getNewNode(7);
	root->right->right = getNewNode(9);
	root->left->left = getNewNode(0);
	root->left->right = getNewNode(4);
	Node* q = root->left->right;
	cout << "The lowest common ancestor is : " << (lowestCommonAncestor(root, p, q))->data;
	_getch();
	return 0;
}

/*void search(Node* root, int p, vector<int> &path)
{
	if (root == NULL) return;
	if (p == root->data) {
		path.push_back(root->data);
		return;
	}		
	else if (p < root->data) {
		path.push_back(root->data);
		search(root->left, p, path);
		return;
	}
	else {
		path.push_back(root->data);
		search(root->right, p, path);
		return;
	}		
}

int lowestCommonAncestor(Node* root, int p, int q) {
	vector<int> path1; vector<int> path2; 
	search(root, p, path1);
	search(root, q, path2); int i;
	for ( i = 0; i < path1.size() && i < path2.size(); i++) {
		if (path1[i] != path2[i])
			break;
	}
	return path1[i-1] ;
}
*/