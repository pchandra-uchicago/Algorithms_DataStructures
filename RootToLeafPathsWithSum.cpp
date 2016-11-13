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
	else if (data <= root->data) {
		root->left = Insert(root->left, data);
	}
	else {
		root->right = Insert(root->right, data);
	}
	return root;
}

void paths(Node* root, int sum, vector<vector<int> > &allPaths, vector<int> &path) {
	if (root == NULL) return;
	if ((root->left == NULL && root->right == NULL) && (sum - root->data == 0)) {
		path.push_back(root->data);
		allPaths.push_back(path);
		path.pop_back();
		return;
	}
	path.push_back(root->data);
	int remSum = sum - root->data;
	paths(root->left, remSum, allPaths, path);
	paths(root->right, remSum, allPaths, path);
	path.pop_back();
	return;
}

vector<vector<int> > allPathSum(Node* root, int sum) {
	vector<vector<int> > allPaths; vector<int> path;
	paths(root, sum, allPaths,path);
	return allPaths;
}

int main()
{
	Node* root = NULL;
	root = Insert(root, 2);
	root = Insert(root, 1);
	root = Insert(root, 3);
	root = Insert(root, 5);
	root = Insert(root, 4);
	vector<vector<int> > result = allPathSum(root, 3);
	_getch();
	return 0;
}
