/* Find the sum of all left leaves in a given binary tree.
    3
   / \
  9  20
    /  \
   15   7
There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24*/
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
	root->left = NULL;
	root->right = NULL;
	return root;
}

void helper(Node* root, bool isLeft, int &sum) {
	if (root == NULL) return;
	if (isLeft == true && root->left == NULL && root->right == NULL)
		sum += root->data;
	helper(root->left, true, sum);
	helper(root->right, false, sum);
}

int sumOfLeftLeaves(Node* root) {
	if (root == NULL) return 0;
	int sum = 0;
	helper(root, false, sum);
	return sum;
}

int main()
{
	Node* root = getNewNode(3);	
	root->left = getNewNode(9);
	root->right = getNewNode(20);
	root->right->left = getNewNode(15);
	root->right->right = getNewNode(7);
	cout << "Sum of left leaves is : " << sumOfLeftLeaves(root);
	_getch();
	return 0;
}
