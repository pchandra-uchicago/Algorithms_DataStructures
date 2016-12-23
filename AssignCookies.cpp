#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s)
{
	sort(g.begin(), g.end());
	sort(s.begin(), s.end()); int i = 0;
	for (int j = 0; i < g.size() && j < s.size(); j++)
	{
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