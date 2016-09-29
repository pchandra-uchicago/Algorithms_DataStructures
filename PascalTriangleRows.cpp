#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

void generateRows(int A, int &rowCount, vector<int> digits, vector<vector<int> > &result) {
	vector<int> rowdigits;	
	if (rowCount == 0) {
		rowdigits.push_back(1);
	}
	else if (rowCount == 1)	{
		rowdigits.push_back(1);
		rowdigits.push_back(1);
	}
	else {
		rowdigits.push_back(1);
		for (int i = 0; i < digits.size() - 1; i++) {
			rowdigits.push_back(digits[i] + digits[i + 1]);
		}
		rowdigits.push_back(1);
	}
	result.push_back(rowdigits);
	rowCount++;
	while (rowCount < A) {
		generateRows(A, rowCount, rowdigits, result);
	}
	return;
}

vector<vector<int> > generate() {
	int A = 3, rowCount = 0; vector<int> digits; vector<vector<int> > result;
	if (A > 0) {
		generateRows(A, rowCount, digits, result);
	}	
	return result;
}
int main()
{	
	generate();
	_getch();
	return 0;
}
