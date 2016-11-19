#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<unordered_map>
#include<algorithm>

using namespace std;
struct Node {
	Node* left;
	Node* right;
	Node* parent;
	int data;
};

Node* getNewNode(int data) {
	Node* root = new Node();
	root->left = NULL;
	root->right = NULL;
	root->parent = NULL;
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
		root->left->parent = root;
	}		
	else {
		root->right = Insert(root->right, data);
		root->right->parent = root;
	}		
	return root;
}

Node* search(Node* root, int data) {
	if (root == NULL) return root;
	if (data == root->data) return root;
	else if (data <= root->data) return search(root->left, data);
	else return search(root->right, data);
}

/* time complexity O(hlogh) h is the height of tree and space complexity is O(1)*/
Node* leastCommonAncestor(Node* root, int n1, int n2) {
	unordered_map<Node*, int> ancestors;
	Node* node1 = search(root, n1);
	Node* node2 = search(root, n2);
	while (node1 != NULL) {
		ancestors[node1] = node1->data;
		node1 = node1->parent;
	}
	while (n2 != NULL) {
		if (ancestors.find(node2) != ancestors.end()) return node2;
		node2 = node2->parent;
	}
	return NULL;
}


int main()
{
	Node* root = NULL;
	root = Insert(root, 20);
	root = Insert(root, 8);
	root = Insert(root, 22);
	root = Insert(root, 4);
	root = Insert(root, 12);
	root = Insert(root, 10);
	root = Insert(root, 14);
	Node* result = leastCommonAncestor(root, 10,14);
	cout << "The least common ancestor of 10 and 14 : " << result->data;
	_getch();
	return 0;
}
