#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

bool searchMatrix(vector<vector<int> > input, int n, int element) {
	int i = 0, j = n - 1; 
	while (i < n && j >= 0) {
		if (input[i][j] == element) return true;
		if (input[i][j] > element) j--;
		else i++;
	}
	return false;
}

int main()
{
	vector<vector<int> > input;
	for (int i = 1; i < 5; i++) {
		vector<int> row; // Create an empty row
		for (int j = 1; j < 5; j++) {
			row.push_back(i * j); // Add an element (column) to the row
		}
		input.push_back(row);
	}
	if (searchMatrix(input, input.size(), 16)) cout << " Element found" << "\n";
	else cout << " Element not found" << "\n";
	_getch();
	return 0;
}