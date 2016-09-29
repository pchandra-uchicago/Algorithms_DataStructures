#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int sqrtSoln(int A) {
	int remainder = A, divisor = 1;
	while (remainder > divisor) {
		remainder = A - pow(divisor, 2);
		if (remainder < 0) {
			break;
		}
		divisor++;
	}
	return (divisor - 1);
}

/* Newton Raphson method*/
int sqrt(int A) {
	if (A <= 0)	{
		return 0;
	}
	double x1 = (A * 1.0) / 2;
	double x2 = (x1 + (A / x1)) / 2;
	while (abs(x1 - x2) >= 0.0000001) {
		x1 = x2;
		x2 = (x1 + (A / x1)) / 2;
	}
	return int(x2);
}

int main()
{
	int i = 257692003;
	cout<< "The square root is " << sqrt(i);
	_getch();
	return 0;
}
