#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<algorithm>

using namespace std;

int partition(int *A, int start, int end) {
	int pivot = A[end];
	int partitionIndex = start;
	for (int i = start; i < end; i++) {
		if (A[i] < pivot) {
			swap(A[i], A[partitionIndex]);
			partitionIndex++;
		}		
	}
	swap(A[partitionIndex], A[end]);
	return partitionIndex;
}

void quickSort(int *A, int start, int end) {
	if (start < end) {
		int partitionIndex = partition(A, start, end);
		quickSort(A, start, partitionIndex - 1);
		quickSort(A, partitionIndex + 1, end);
	}	
}

int main()
{
	int A[] = { 7,6,5,4,3,2,1,0 };
	quickSort(A, 0, 7);
	for (int i = 0; i < 8; i++) cout << A[i] << " ";
	_getch();
	return 0;
}
