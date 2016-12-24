#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	unordered_set<int> s(nums1.begin(), nums1.end());
	vector<int> result;
	for(auto i:nums2) {
		if (s.count(i)) {
			result.push_back(i);
			s.erase(i);
		}
	}
	return result;
}

int main()
{
	vector<int> n1, n2;
	n1.insert(n1.end(), { 1,2,2,1 });
	n2.insert(n2.end(), { 2,3});
	intersection(n1, n2);
	_getch();
	return 0;
}