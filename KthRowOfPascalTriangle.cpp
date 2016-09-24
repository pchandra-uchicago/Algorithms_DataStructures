#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

void recursiveCall(int &rowCount, int A, vector<int> digits, vector<int> &result, bool &flag)
{
	vector<int> rowdigits;	
	if (rowCount == 0)
	{
		rowdigits.push_back(1);
	}
	else if (rowCount == 1)
	{
		rowdigits.push_back(1);
		rowdigits.push_back(1);
	}
	else
	{
		rowdigits.push_back(1);
		for (int i = 0; i < digits.size()-1; i++)
		{				
			rowdigits.push_back(digits[i] + digits[i + 1]);
		}
		rowdigits.push_back(1);
	}
	rowCount++;

	while (rowCount <= A)
	{
		recursiveCall(rowCount, A, rowdigits, result, flag);			
	}

	if (flag)
	{
		result.swap(rowdigits);
		flag = false;
	}	
}

vector<int> kthRowOfPascalTriangle(int A)
{
	vector<int> digits; vector<int> result; int rowCount = 0; bool flag = true;
	recursiveCall(rowCount, A, digits, result, flag);	
	return result;
}

int main()
{
	kthRowOfPascalTriangle(3);
	_getch();
	return 0;
}

void insert(vector<int> &v, int index, int val) {
	if (index >= v.size()) {
		v.push_back(val);
	}
	else {
		v[index] = val;
	}
}
vector<int> getRow(int rowIndex) {
	vector<int> ans[2];
	int numRows = rowIndex + 1;
	if (numRows <= 0) {
		return ans[0];
	}
	int curRow = 0, prevRow = 1;
	ans[0].push_back(1);
	for (int i = 1; i < numRows; i++) {
		swap(curRow, prevRow);
		insert(ans[curRow], 0, 1);
		for (int j = 0; j < ans[prevRow].size() - 1; j++) {
			insert(ans[curRow], j + 1, ans[prevRow][j] + ans[prevRow][j + 1]);
		}
		insert(ans[curRow], ans[prevRow].size(), 1);
	}
	return ans[curRow];
}