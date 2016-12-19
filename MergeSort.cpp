#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<algorithm>

using namespace std;

void merge(int *left, int *right, int *A) {
	int leftSize = sizeof(left) / sizeof(left[0]);
	int rightSize = sizeof(right) / sizeof(right[0]);
	int i =0, j =0, k = 0;
	while (i < leftSize && j < rightSize) {
		if (left[i] < right[j]) {
			A[k] = left[i];
			i = i + 1;
		}
		else {
			A[k] = right[j];
			j = j + 1;
		}
		k = k + 1;
	}
	while (i < leftSize) {
		A[k] = left[i]; i++; k++;
	}
	while (j < rightSize) {
		A[k] = right[j]; j++; k++;
	}
}

void mergeSort(int *A, int size) {
	//int size = sizeof(A) / sizeof(A[0]);
	if (size < 2) return;
	int mid = size / 2;
	int *left = new int[mid]; int *right = new int[size - mid];
	for (int i = 0; i < mid; i++) left[i] = A[i];
	for (int i = mid; i < size - 1; i++) right[i] = A[i];
	mergeSort(left, sizeof(left)/sizeof(left[0]));
	mergeSort(right, sizeof(right) / sizeof(right[0]));
	merge(left, right, A);
}

int main()
{
	int A[] = { 7,6,5,4,3,2,1,0 };
	mergeSort(A, sizeof(A) / sizeof(A[0]));
	for (int i = 0; i < 8; i++) cout << A[i] << " ";
	_getch();
	return 0;
}
