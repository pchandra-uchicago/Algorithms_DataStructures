#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<algorithm>
#include<string>

using namespace std;

int longestCommonSubsequence(char *A, char *B, int m, int n) {
	int** L = new int*[m + 1];
	for (int i = 0; i <= m; i++)
		L[i] = new int[n + 1];
	
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0)
				L[i][j] = 0;
			else if (A[i - 1] == B[j - 1])
				L[i][j] = L[i - 1][j - 1] + 1;
			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}
	return L[m][n];
}

int main()
{
	char A[] = "AGGTAB";
	char B[] = "GXTXAYB";
	int length = longestCommonSubsequence(A, B, strlen(A), strlen(B));
	_getch();
	return 0;
}
