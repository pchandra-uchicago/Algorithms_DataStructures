#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;

void reverseQueue(queue<int> q) {
	stack<int> s;
	while (!q.empty()) {
		s.push(q.front());
		q.pop();
	}
	cout << "Reversed Queue : ";
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
}

int main()
{
	queue<int> q;
	q.push(2);
	q.push(5);
	q.push(6);
	q.push(4);
	cout << "Items in queue are :";
	while (!q.empty()) {
		cout << q.front() << "";
		q.pop();
	}
	reverseQueue(q);	
	_getch();
	return 0;
}