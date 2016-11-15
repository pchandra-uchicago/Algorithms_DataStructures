#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

void maxProfit(const vector<int> &A) {
	bool buy = false; vector<pair<int, int> > buySell; pair<int, int> index;
	for (int i = 0; i < A.size() - 1; i++) {
		if (A[i] < A[i + 1] && buy ==  false) {
			buy = true;
			index.first = i;
		}
		else if(A[i] > A[i+1] && buy == true) {
			buy = false;
			index.second = i;
			buySell.push_back(index);
			index = make_pair(0, 0);
		}
	}
	if (buy) {
		index.second = A.size() - 1;
		buySell.push_back(index);
	}
	for (auto it = buySell.begin(); it != buySell.end(); it++) {
		cout << "Buy on Day:" << it->first << " Sell on Day:" << it->second << "\n";
	}
}

int main()
{
	vector<int> input;
	input.push_back(100);
	input.push_back(180);
	input.push_back(260);
	input.push_back(310);
	input.push_back(40);
	input.push_back(535);
	input.push_back(695);
	maxProfit(input);
	_getch();
	return 0;
}