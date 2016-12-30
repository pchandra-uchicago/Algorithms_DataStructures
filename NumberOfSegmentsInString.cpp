/*Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.
Please note that the string does not contain any non-printable characters. 
Input: "Hello, my name is John"  Output: 5*/
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<regex>

using namespace std;

int countSegments(string s) {
	int count = 0; char prevChar = ' '; bool isAlpha = false;
	if (s.empty()) return 0;
	for (char& c : s) {
		if (isspace(c) && (prevChar != c))
			count++;			
		prevChar = c;
		if (prevChar != ' ' && !isAlpha) isAlpha = true;
	}
	if (count == 0) {
		if (isAlpha) return count + 1;
		else return count;
	}
	if (prevChar == ' ') return count;
	return count+1;
}

int main()
{
	cout << "The number of segments is : " << countSegments("hello");
	_getch();
	return 0;
}
