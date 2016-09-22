#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> printInSpiralOrder(const vector<vector<int> > &A)
{
	vector<int> result;
	int dir = 0;
	int top = 0; int bottom = A.size() - 1; int left = 0; int right = A[0].size() - 1;

	while (top <= bottom && left <= right)
	{
		if(dir == 0)
		{
			for (int i = left; i <= right ; i++)
			{
				result.push_back(A[top][i]);
			}
			top++;			
		}
		else if (dir == 1)
		{
			for (int i = top; i <= bottom; i++)
			{
				result.push_back(A[i][right]);
			}
			right--;			
		}
		else if (dir == 2)
		{
			for (int i = right; i >= left; i--)
			{
				result.push_back(A[bottom][i]);
			}
			bottom--;			
		}
		else if (dir==3)
		{
			for (int i = bottom; i >= top; i--)
			{
				result.push_back(A[i][left]);
			}			
			left++;
		}
		dir = (dir + 1) % 4;
	}
	return result;
}

int main()
{
	vector< vector<int> > vec;
	for (int i = 1; i < 4; i++) {
		vector<int> row; // Create an empty row
		for (int j = 0; j < 4; j++) {
			row.push_back(i * j); // Add an element (column) to the row
		}
		vec.push_back(row); // Add the row to the main vector
	}

	vector<int> result = printInSpiralOrder(vec);
	for (vector<int>::iterator i = result.begin(); i != result.end(); i++)
	{
		cout << *i << ',';
	}
	_getch();
	return 0;
}
