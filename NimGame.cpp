#include<iostream>
#include<conio.h>
#include<stdio.h>

using namespace std;

bool canWinNim(int n)
{
	if (n < 4) return true;
	else if (n % 4 == 0) return false;
	else return true;	
}

int main()
{
	if (canWinNim(3)) cout << " I can win ";
	else cout << " I can't win ";
	_getch();
	return 0;
}