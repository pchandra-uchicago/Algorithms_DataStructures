#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
	int count = 0; int size = nums.size();
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] != 0) {
			nums[count] = nums[i];
			count++;
		}
	}
	while(count < size)
		nums[count++] = 0;
}

int main()
{
	vector<int> nums;
	nums.insert(nums.end(), { 0, 1, 0, 3, 12 });
	moveZeroes(nums);
	_getch();
	return 0;
}
