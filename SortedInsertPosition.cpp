#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int searchInsert(vector<int> &A, int B) {	
	int low = 0, high = A.size() - 1, mid, result = -1;
	while (low <= high) {
		mid = (low + (high - low) / 2);
		if (A[mid] == B) {
			return mid;
		}
		else if (B < A[mid]) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	if (A[mid] > B)	{
		return mid;
	}
	else {
		return mid +1;
	}	
}

int main()
{
	vector<int> A;
	A.push_back(1);
	A.push_back(3);
	A.push_back(5);
	A.push_back(6);

	searchInsert(A, 2);
	_getch();
	return 0;
}
