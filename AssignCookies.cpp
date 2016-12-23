/*Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie. 
Each child i has a greed factor gi, which is the minimum size of a cookie that the child will be content with; and each cookie j has 
a size sj. If sj >= gi, we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number 
of your content children and output the maximum number.
Note:
You may assume the greed factor is always positive. 
You cannot assign more than one cookie to one child.*/
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

/*Greedy algorithm*/
int findContentChildren(vector<int>& g, vector<int>& s) {
	sort(g.begin(), g.end());
	sort(s.begin(), s.end()); int i = 0;
	for (int j = 0; i < g.size() && j < s.size(); j++) {
		if (g[j] < s[j]) i++;
	}
	return i;
}

int main()
{
	vector<int> g; vector<int> s;
	g.push_back(1);
	g.push_back(2);
	g.push_back(3);
	s.push_back(1);
	s.push_back(1);
	findContentChildren(g, s);
	_getch();
	return 0;
}
