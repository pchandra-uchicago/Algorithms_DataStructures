#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string>
#include<algorithm>

using namespace std;

bool isVowel(char c) {
	if ((c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')) return true;
	return false;
}

string reverseVowels(string s) {
	int i = 0; int j = s.size() - 1;
	while (i < j) {
		char c1 = tolower(s[i]);
		char c2 = tolower(s[j]);
		if (isVowel(c1) && isVowel(c2)) {
			swap(s[i], s[j]);
			i++; j--;
		}	
		else if (isVowel(c1)) j--;
		else if (isVowel(c2)) i++;
		else {
			i++; j--;
		}		
	}
	return s;
}

int main()
{
	cout << "Reversed vowels string : " << reverseVowels("LeetCOde");
	_getch();
	return 0;
}