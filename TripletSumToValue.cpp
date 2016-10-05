#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

vector<int> tripletSum(vector<int> A, int B) {
	/*sort the array*/
	std::sort(A.begin(), A.end());

	vector<int> result;
	int left, right;
	for (int i = 0; i < A.size()-2; i++) {
		left = i + 1;
		right = A.size() - 1;
		while (left < right) {
			if (A[i] + A[left] + A[right] == B) {
				result.insert(result.end(), { A[i], A[left], A[right] });
				return result;
			}
			else if (A[i] + A[left] + A[right] < B) 
				left++;
			else // A[i] + A[l] + A[r] > sum
				right--;
		}		
	}
	return result;
}

int main()
{
	vector<int> A;
	A.insert(A.end(), { 1,4, 45, 6, 10, 8 });

	/* time complexity is O(n^2)*/
	tripletSum(A, 22);
	_getch();
	return 0;
}