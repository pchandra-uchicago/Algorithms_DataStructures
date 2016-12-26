#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int rob(vector<int>& nums) {
	int evenSum = 0, oddSum = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (i % 2 == 0)
			evenSum = max(evenSum + nums[i], oddSum);
		else
			oddSum = max(evenSum, oddSum + nums[i]);
	}
	return max(evenSum, oddSum);
}

int main()
{
	vector<int> nums;
	nums.insert(nums.end(), { 2,1,1,2});
	cout << "Maximum amount that can be robbed is : " << rob(nums);
	_getch();
	return 0;
}