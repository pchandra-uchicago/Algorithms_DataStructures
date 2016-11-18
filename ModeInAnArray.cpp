#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int maxRepeatingElement(int *arr, int n, int k)
{
	for (int i = 0; i< n; i++)
		arr[arr[i] % k] += k;

	// finds index of most repeating element
	int max = arr[0], result = 0;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			result = i;
		}
	}
	/* this code gives the original array back
	for (int i = 0; i< n; i++)
	arr[i] = arr[i]%k; */
	return result;
}

int main()
{
	int a[] = {2,3,3,5,3,4,1,7};
	int result = maxRepeatingElement(a, sizeof(a) / sizeof(a[0]), 8);
	_getch();
	return 0;
}