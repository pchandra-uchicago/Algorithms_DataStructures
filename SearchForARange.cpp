#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int binarySearch(const vector<int> &A, int n, int x, bool searchFirst) {
	int low = 0, high = n - 1, mid, result = -1;
	while (low <= high) {
		mid = (low + (high - low) / 2);
		if (A[mid] == x) {
			result = mid;

			if (searchFirst) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}			
		}
		else if (x < A[mid]) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return result;
}

vector<int> searchRange(const vector<int> &A, int B) {
	vector<int> result;
	result.push_back(binarySearch(A, A.size(), B, true));
	result.push_back(binarySearch(A, A.size(), B, false));
	return result;
}

int main()
{
	vector<int> A;
	A.push_back(1);
	/*A.push_back(7);
	A.push_back(7);
	A.push_back(8);
	A.push_back(8);
	A.push_back(10); */	
	searchRange(A, 1);
	_getch();
	return 0;
}
