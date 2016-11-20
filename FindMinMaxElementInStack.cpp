#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

class StackMinMax
{
	private: stack<int> minstack;
			 stack<int> maxstack;
			 stack<int> basestack;
	public:	void push(int value);
			int pop();
			int findMin();
			int findMax();
};

void StackMinMax::push(int value)
{
	int tmin = findMin();
	int tmax = findMax();
	if (value <= findMin())	minstack.push(value);
	if (value >= findMax())	maxstack.push(value);
	basestack.push(value);
}

int StackMinMax::pop()
{
	int popped = basestack.top();
	basestack.pop();
	if (popped == findMin()) minstack.pop();
	if (popped == findMax()) maxstack.pop();
	return popped;
}

int StackMinMax::findMin()
{
	if (minstack.empty()) return INT_MAX;
	else return minstack.top();
}

int StackMinMax::findMax()
{
	if (maxstack.empty()) return INT_MIN;
	else return maxstack.top();
}

int main()
{	
	StackMinMax s;
	s.push(7);
	s.push(1);
	s.push(5);
	s.push(3);
	s.push(7);
	s.push(4);
	s.pop();
	cout << "Min and Max elements are : " << s.findMin() << " and " << s.findMax();
	_getch();
	return 0;
}