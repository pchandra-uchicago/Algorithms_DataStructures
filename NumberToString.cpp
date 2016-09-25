#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<string>
#include<sstream>
using namespace std;

string finalString = "";

string convertNumberToString(string inputNumber){
	int stringSize = inputNumber.length();
	int num_dec = stoi(inputNumber);
	string strdigit;
	string tenMultiples[] = {" ","ten", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eigty", "ninty"};
	string unitDigits[] = {" ", "One", "Two", "three", "four", "five", "six", "seven", "eight", "nine"};
	string two_digits[] = {"", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};	

	if(stringSize > 2) {
		string str = inputNumber.substr(stringSize-3);				
		if(num_dec%100 >= 10 && num_dec%100 <= 19 ) {
			strdigit = unitDigits[(str.at(0) - '0')] + " " + "hundred" + " " + two_digits[(num_dec%10) +1];
		}
		else {		
			strdigit = unitDigits[(str.at(0) - '0')] + " " + "hundred" + " " + tenMultiples[(str.at(1) - '0')] + " " + 
																									unitDigits[(str.at(2) - '0')];
		}		
	}
	else  {
		if(num_dec > 20) {
			strdigit = tenMultiples[(inputNumber.at(0) - '0')] + " " + unitDigits[(inputNumber.at(1) - '0')];
		}
		else if(num_dec < 10) {
			strdigit = unitDigits[(inputNumber.at(0) - '0')];
		}
		else {
			strdigit = two_digits[(num_dec%10) +1];
		}
	}
	return strdigit;		
}

string dealsWithLargeNumbers(string inputNumber) {
	int stringSize = inputNumber.length();
	static int count = 0;
	string newStr,  str;

	if(stringSize >= 3) {
		 str = inputNumber.substr(stringSize-3);
	}
	else {
		str = inputNumber;
	}
	switch(count) {
		case 0 : finalString = convertNumberToString(str) + " " + finalString;
			break;
		case 1: finalString = convertNumberToString(str) + " " + "thousand" +  " " + finalString;
			break;
		case 2: finalString = convertNumberToString(str) + " " + "million" + " " + finalString;
			break;
		case 3: finalString = convertNumberToString(str) + " " + "billion" + " " + finalString;
			break;
		default: cout << " That's a little too much";
			break;
	}	
	if(stringSize > 3) {
		str = inputNumber.erase(stringSize-3);
		count ++ ;
		dealsWithLargeNumbers(str) ;
	}
	return finalString;
}

int main()
{
	string input, output;
	cout << "Enter the input Number" << endl;
	cin >> input;		
	output = dealsWithLargeNumbers(input);
	cout << output;
	getch();
	return 0;
}


 
