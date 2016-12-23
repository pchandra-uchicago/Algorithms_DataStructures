#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string>

using namespace std;

/*in place reversal of string */
string reverseString(string s) {
	int i = 0; int j = s.size() - 1;
	while(i < j) {
		swap(s[i], s[j]);
		i++; j--;
	}
	return s;
}

int main()
{
	string inputStr = "Whatsupp";
	reverseString(inputStr);
	_getch();
	return 0;
}
