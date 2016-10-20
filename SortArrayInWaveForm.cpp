#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
// This function sorts arr[0..n-1] in wave form, i.e., arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= arr[5] ....
void sortInWave(int arr[], int n) {
	// Traverse all even elements
	for (int i = 0; i < n; i += 2) {		
		if (i>0 && arr[i - 1] > arr[i])
			swap(&arr[i], &arr[i - 1]);		
		if (i<n - 1 && arr[i] < arr[i + 1])
			swap(&arr[i], &arr[i + 1]);
	}
}
int main()
{
	int arr[] = { 10, 90, 49, 2, 1, 5, 23 };
	int n = sizeof(arr) / sizeof(arr[0]);
	sortInWave(arr, n);
	for (int i = 0; i<n; i++)
		cout << arr[i] << " ";
	_getch();
	return 0;
}
