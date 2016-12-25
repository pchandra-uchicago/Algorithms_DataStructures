/*Given two binary trees, write a function to check if they are equal or not.
Two binary trees are considered equal if they are structurally identical and the nodes have the same value.*/
#include<iostream>
#include<conio.h>
#include<stdio.h>
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

bool isSameTree(Node* p, Node* q) {
	if (p != NULL && q != NULL) {
		if (p->data != q->data) return false;
		if(isSameTree(p->left, q->left )&& isSameTree(p->right, q->right))
			return true;
		else return false;
	}
	return true;	
}
int main()
{
	Node* p = getNewNode(4);
	p->left = getNewNode(2);
	p->right = getNewNode(7);
	p->right->left = getNewNode(6);
	p->right->right = getNewNode(9);
	p->left->left = getNewNode(1);
	p->left->right = getNewNode(3);
	Node* q = getNewNode(4);
	q->left = getNewNode(2);
	q->right = getNewNode(7);
	q->right->left = getNewNode(6);
	q->right->right = getNewNode(9);
	q->left->left = getNewNode(1);
	q->left->right = getNewNode(3);
	if (isSameTree(p, q))
		cout << " Both tree are identical ";
	else
		cout << "Both trees aren't identical";
	_getch();
	return 0;
}
