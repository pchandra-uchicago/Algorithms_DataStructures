#include<iostream>
#include <stdio.h>
#include<conio.h>

using namespace std;

void findDuplicates(int *arr, int size)
{
	cout<<"duplicates elements are: ";
	for (int i = 0; i < size; i++) {
		if (arr[abs(arr[i])] >= 0)
			arr[abs(arr[i])] = -arr[abs(arr[i])];
		else
			cout<< abs(arr[i]) << " ";
	}
}

int main()
{
	int arr[] = { 1, 2, 3, 1, 3, 6, 6 };	
	findDuplicates(arr, sizeof(arr) / sizeof(arr[0]));
	_getch();
	return 0;
}