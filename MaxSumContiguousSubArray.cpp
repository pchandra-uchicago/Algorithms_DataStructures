#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<vector>
#include<algorithm>
#include<iterator>
#include<map>

using namespace std;

int maxSubArray(const vector<int> &A)
{
	int old_sum = 0; int new_sum = 0; int count = 0;
	if (A.size() <= 1)
	{
		return A[0];
	}
	for (int i = 0; i != A.size(); i++)
	{
		new_sum = new_sum + A[i];

		if (old_sum < new_sum)
		{
			old_sum = new_sum;
		}
		else if (new_sum < 0)
		{
			new_sum = 0;
		}

		if (A[i] < 0)
		{
			count++;
		}
	}
	if (count == A.size())
	{
		return *(max_element(A.begin(), A.end()));
	}
	return old_sum;	
}

/*You keep accumulating sum till the sum becomes < 0, at which point you start over again, 
discarding the accumulated sum.*/
int maxSubArraySoln(const vector<int> &A) {
	int n = A.size();
	int curSum = 0, maxSum = -1000000000;
	for (int i = 0; i < n; i++) 
	{
		curSum += A[i];
		maxSum = max(maxSum, curSum);
		if (curSum < 0) curSum = 0;
	}
	return maxSum;
}

/* This algorithm is also called Kadane's Algorithm */
int main()
{
	vector<int> A;
	A.push_back(-2);
	A.push_back(-3);
	A.push_back(5);
	A.push_back(-10);
	/*A.push_back(4);
	A.push_back(-1);
	A.push_back(-2);
	A.push_back(1);
	A.push_back(5);
	A.push_back(-3);*/
	//A.push_back(-500);
	
	cout << "Max sum is :" << maxSubArray(A);

	_getch();
	return 0;
}
