#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> repeatedNumber(const vector<int> &A)
{
	long max_num = *(max_element(A.begin(), A.end()));	
	vector<int> result;

	long actualSum = 0, NSum = ((long long)max_num * (long long)(max_num+1))/2, missingNum = 0, dupeNum = 0;

	long NSumsquare = ((long long)max_num * (long long)(max_num + 1) * (2 * (long long)max_num + 1)) / 6;
	long actualSumsquare = 0;

	for (int i = 0; i <= A.size()-1; i++) {
		actualSum += (long long)A[i];
		actualSumsquare += (long long) A[i] * (long long) A[i];
	}

	dupeNum = ((long long)(actualSum - NSum) + ((long long)(actualSumsquare -NSumsquare)/ (long long)(actualSum - NSum)))/2;

	missingNum = dupeNum - (long long)(actualSum - NSum);
	result.push_back(int(dupeNum));
	result.push_back(int(missingNum));

	return result;
}

vector<int> repeatedNumberSoln(const vector<int> &V) {
	long long sum = 0;
	long long squareSum = 0;
	long long temp;
	for (int i = 0; i < V.size(); i++) {
		temp = V[i];
		sum += temp;
		sum -= (i + 1);
		squareSum += (temp * temp);
		squareSum -= ((long long)(i + 1) * (long long)(i + 1));
	}
	// sum = A - B
	// squareSum = A^2 - B^2 = (A - B)(A + B)
	// squareSum / sum = A + B
	squareSum /= sum;

	// Now we have A + B and A - B. Lets figure out A and B now. 
	int A = (int)((sum + squareSum) / 2);
	int B = squareSum - A;

	vector<int> ret;
	ret.push_back(A);
	ret.push_back(B);
	return ret;
}

int main()
{
	vector<int> input;
	input.push_back(8);
	input.push_back(1);
	input.push_back(2);
	input.push_back(3);
	input.push_back(5);
	input.push_back(4);
	input.push_back(6);
	input.push_back(7);
	input.push_back(8);
	input.push_back(10);	

	vector<int> result = repeatedNumber(input);

	for (vector<int>::iterator i = result.begin(); i != result.end(); i++)
	{
		cout << *i << '\t';
	}
	
	_getch();
	return 0;
}
