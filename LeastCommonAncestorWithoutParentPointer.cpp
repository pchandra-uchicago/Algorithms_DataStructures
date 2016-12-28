/*Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node 
in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
          __6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5       For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. 
Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.*/
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

Node* getNewNode(int data) {
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

void search(Node* root, Node* p, vector<Node*> &path) {
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
