#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int lengthOfLongestSubstring(string A) {
	if (A.size() <= 1)
		return A.size();	
	char curChar, nextChar; vector<int> strLength; int currIndex = 0; bool flag = true;	
	for (int i = 1; i < A.size(); i++) {
		nextChar = A[i];
		for (int j = currIndex; j < i; j++) {
			curChar = A[j];
			if (curChar == nextChar) {				
				if (i != A.size() - 1) {
					strLength.push_back(i - currIndex);
					/*if the reptitive char are adjacent to each other*/
					if (i == j + 1)
						currIndex = i;
					else
						currIndex = j + 1;
				}
				else 
					flag = false;													
				break;
			}			
		}
		/*decide if the last character needs to be counted or not*/
		if (i == A.size()-1) {
			if (flag)			
				strLength.push_back(i - currIndex + 1);			
			else			
				strLength.push_back(i - currIndex);			
		}		
	}
	return *(max_element(strLength.begin(), strLength.end()));
}

int main()
{
	string str = "dadbc";
	int temp = str.length();
	int len = lengthOfLongestSubstring(str);
	_getch();
	return 0;	
}
