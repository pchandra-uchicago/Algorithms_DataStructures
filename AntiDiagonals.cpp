#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int> > diagonal(vector<vector<int> > &A) {
	int row = 0, col = 0;
	vector<vector<int> > result; vector<int>diag;
	
	for (int i = 0; i <= A.size() - 1; i++)	{
		col = i;
		row = 0;
		while (col >= 0) {
			diag.push_back(A[row][col]);
			row++;
			col--;
		}
		result.push_back(diag);
		diag.clear();
	}	
	/* loop through second half of the matrix*/
	row = 1; int count = 1;
	while(row <= A.size() - 1) {
		col = A.size() - 1;
		while (row <= A.size() - 1) {
			diag.push_back(A[row][col]);
			row++;
			col--;
		}
		result.push_back(diag);
		count++;
		row = count;
		diag.clear();
	}
	return result;
}

int main()
{
	vector< vector<int> > vec;
	for (int i = 1; i < 4; i++) {
		vector<int> row; // Create an empty row
		for (int j = 1; j < 4; j++) {
			row.push_back(i * j); // Add an element (column) to the row
		}
		vec.push_back(row); // Add the row to the main vector
	}
	diagonal(vec);
	_getch();
	return 0;
}
