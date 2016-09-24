#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int> > generateMatrix(int A)
{
	vector<vector<int>> result(A);
	int dir = 0; int num = 1;
	int top = 0; int bottom = A- 1; int left = 0; int right = A - 1;
	/*creates a dummy 2d vector in matrix form*/
	for (int i = top; i <= bottom; i++)
	{
		result[i].resize(A);
	}
	while (top <= bottom && left <= right)
	{
		if (dir == 0)
		{
			for (int i = left; i <= right; i++)
			{
				result[top][i] = num;
				num++;
			}
			top++;
		}
		else if (dir == 1)
		{
			for (int i = top; i <= bottom; i++)
			{
				result[i][right] = num;
				num++;				
			}
			right--;
		}
		else if (dir == 2)
		{
			for (int i = right; i >= left; i--)
			{
				result[bottom][i] = num;
				num++;				
			}
			bottom--;
		}
		else if (dir == 3)
		{
			for (int i = bottom; i >= top; i--)
			{
				result[i][left] = num;
				num++;				
			}
			left++;
		}
		dir = (dir + 1) % 4;
	}
	return result;
}

int main()
{
	int A = 3;
	vector<vector<int>>result = generateMatrix(A);	
	return 0;
}
