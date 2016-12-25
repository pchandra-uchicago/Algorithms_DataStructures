#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int climbStairs(int n) {
	if (n <= 2) return n; ; vector<int> ways(n+1); ways[1] = 1; ways[2] = 2;
	for(int i = 3; i <= n; i++)
		ways[i] = ways[i - 1] + ways[i - 2];
	return ways[n];
}

int main()
{
	cout << "The number of ways to climb stairs with n steps is : " << climbStairs(10);
	_getch();
	return 0;
}