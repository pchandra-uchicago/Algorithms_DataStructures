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
	//removeDuplicates(nums);
	cout << "The length of array without duplicates is : " << removeDuplicates(nums);
	_getch();
	return 0;
}