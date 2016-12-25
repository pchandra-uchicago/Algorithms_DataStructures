/*Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring 
together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.
Input: "abcabcabcabc"  Output: True  Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)*/
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string>

using namespace std;

bool repeatedSubstringPattern(string str) {
	int len = str.length();
	for (int i = 1; i <= len / 2; i++) {
		if (len%i == 0 && (str.substr(i) == str.substr(0, len - i)))
			return true;
	}		
	return false;
}

int main()
{
	if (repeatedSubstringPattern("abaababaab"))
		cout << "The string can be constructed by taking a substring of it";
	else
		cout << "The string can't be constructed by taking a substring of it";
	_getch();
	return 0;
}
