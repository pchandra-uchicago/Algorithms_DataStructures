/*Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
For example,
Given input array nums = [1,1,2],
Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you
leave beyond the new length.*/
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
	int count = 0; int size = nums.size();
	if (nums.size() == 1) return 1;	
	int i = 1;
	while (i < nums.size()) {
		if (nums[i - 1] == nums[i]) {
			nums.erase(nums.begin() + i);
			count++;
		}
		else
			i++;
	}
	return (size - count);
}

int main()
{
	vector<int> nums;
	nums.insert(nums.end(), {1,1,2});
	cout << "The length of array without duplicates is : " << removeDuplicates(nums);
	_getch();
	return 0;
}
