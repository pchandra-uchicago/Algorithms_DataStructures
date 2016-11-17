#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<vector>
#include<algorithm>

using namespace std;

int maxProfit(const vector<int> &A)
{
	int max_diff = A[1] - A[0];
	int min_element = A[0];
	for (int i = 1; i <= A.size() - 1; i++)
	{
		if (A[i] - min_element > max_diff)
		{
			max_diff = A[i] - min_element;
		}
		if (A[i] < min_element)
		{
			min_element = A[i];
		}
	}
	return max_diff;
}

int main()
{
	vector<int> input;
	input.push_back(2);
	input.push_back(3);
	input.push_back(10);
	input.push_back(6);
	input.push_back(4);
	input.push_back(8);
	input.push_back(1);
	int result = maxProfit(input);
	_getch();
	return 0;
}