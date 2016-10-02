#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int Search(const vector<int> &A, int B)
{
	int low = 0, high = A.size() - 1, mid;

	while (low <= high) {
		mid = (low + (high - low) / 2);
		if (A[mid] == B) {
			return mid;
		}
		else if (A[mid] <= A[high]) {
			if (B > A[mid] && B <= A[high]) {
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
		else {
			if (A[low] <= A[mid]) {
				if (B >= A[low] && B < A[mid]) {
					high = mid - 1;
				}
				else {
					low = mid + 1;
				}
			}
		}
	}
	return -1;
}

int main()
{
	vector<int> A;
	A.push_back(4);
	A.push_back(5);
	A.push_back(6);
	A.push_back(7);
	A.push_back(0);
	A.push_back(1);
	A.push_back(2);

	int result = Search(A, 6);
	_getch();
	return 0;
}