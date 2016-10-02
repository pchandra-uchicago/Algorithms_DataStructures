#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int getOddOccurences(vector<int> A) {
	int result = 0;
	for (int i = 0; i < (A.size()/A[0])-1; i++) {
		result = result ^ A[i];
	}
	return result;
}

int main()
{
	vector<int> A;
	A.push_back(2);
	A.push_back(3);
	A.push_back(5);
	A.push_back(4);
	A.push_back(5);
	A.push_back(2);
	A.push_back(4);
	A.push_back(3);
	A.push_back(5);
	
	cout << "The odd occurences are " << getOddOccurences(A);
	_getch();
	return 0;
}
