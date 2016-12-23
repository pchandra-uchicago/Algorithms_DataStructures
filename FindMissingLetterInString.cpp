#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string>
#include<string.h>

using namespace std;

char findTheDifference(string s, string t) {
	int i = 0; int sum1 = 0, sum2 = 0;
	while (i != s.size()) {
		sum1 += s[i];
		sum2 += t[i];
		i++;
	}
	sum2 += t[i];
	return static_cast<char>(sum2-sum1);
}

int main()
{
	cout << "The difference is " << findTheDifference("abcd", "abkcd");
	_getch();
	return 0;
}
