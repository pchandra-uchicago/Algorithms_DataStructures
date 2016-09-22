#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> addPlusOne(vector<int> &A)
{
	int carry = 0;
	vector<int> result;
	
	for(int i = A.size() - 1; i >= 0; i--)
	{
		if (i == A.size() - 1)
		{
			if (A[i] + 1 > 9)
			{
				result.push_back(0);
				carry = 1;
				if (A.size() == 1)
				{
					result.push_back(carry);
				}
			}
			else 
			{
				result.push_back(A[i] + 1);
			}
		}			
		else
		{			
			if (A[i] + carry > 9)
			{
				carry = 1;
				result.push_back(0);
				if (i==0)
				{
					result.push_back(1);
				}
			}
			else
			{
				result.push_back(A[i] + carry);
				carry = 0;
			}			
		}
	}
	std::reverse(result.begin(), result.end());
	while (result.size() > 1 && result[0] == 0)
	{
		result.erase(result.begin());
	}
	return result;
}

vector<int> plusOne(vector<int> &digits) {
	reverse(digits.begin(), digits.end());
	vector<int> ans;
	int carry = 1;
	for (int i = 0; i < digits.size(); i++) {
		int sum = digits[i] + carry;
		ans.push_back(sum % 10);
		carry = sum / 10;
	}
	while (carry) {
		ans.push_back(carry % 10);
		carry /= 10;
	}
	while (ans[ans.size() - 1] == 0 && ans.size() > 1) {
		ans.pop_back();
	}
	reverse(ans.begin(), ans.end());
	reverse(digits.begin(), digits.end());
	return ans;
}
int main()
{
	vector<int> input;
	input.push_back(0);
	input.push_back(1);
	input.push_back(2);
	input.push_back(9);
	input.push_back(6);
	input.push_back(9);

	vector<int> result = addPlusOne(input);

	for (vector<int>::iterator i = result.begin(); i != result.end(); i++)
	{
		cout << *i << ' ';
	}
	_getch();
	return 0;
}
