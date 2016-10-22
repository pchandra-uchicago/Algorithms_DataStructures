#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<algorithm>

using namespace std;

int binomialCoeff(int n, int k) {	
	int** C = new int*[n+1];
	for (int i = 0; i <= n; ++i)
		C[i] = new int[k+1];
	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= min(i,k); j++) {
			if (j == 0 || j == i)
				C[i][j] = 1;
			else
				C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}
	return C[n][k];
}

int main()
{
	int n=5, k=2;
	int result = binomialCoeff(n, k);
	_getch();
	return 0;
}
