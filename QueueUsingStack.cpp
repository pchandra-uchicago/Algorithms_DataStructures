#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;

void enQueue(int x, stack<int> &s1){
	s1.push(x);
}

int deQueue(stack<int> &s1) {
	stack<int> s2;
	if (s1.empty()) return 0;
	while (!s1.empty()) {
		s2.push(s1.top());
		s1.pop();
	}
	int popped = s2.top();
	s2.pop();
	while (!s2.empty()) {
		s1.push(s2.top());
		s2.pop();
	}
	return popped;
}

int main()
{
	stack<int> s1;
	enQueue(2, s1);
	enQueue(4, s1);
	enQueue(6, s1);
	enQueue(8, s1);
	cout << "Popped element is : " << deQueue(s1);
	enQueue(10, s1);
	cout << "Popped element is : " << deQueue(s1);
	_getch();
	return 0;
}