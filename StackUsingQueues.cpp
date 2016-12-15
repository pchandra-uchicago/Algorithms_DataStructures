#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<queue>
#include<algorithm>

using namespace std;

void push(int x, queue<int> &q1)
{
	q1.push(x);
}

int pop(queue<int> &q1)
{
	queue<int> q2;
	int size = q1.size(); int count = 0;
	if (q1.empty()) return 0;
	while (count != size - 1)
	{
		q2.push(q1.front());
		q1.pop();
		count++;
	}
	int popped = q1.front();
	q1.pop();
	while (!q2.empty())
	{
		q1.push(q2.front());
		q2.pop();
	}
	return popped;
}

int main()
{
	queue<int> q1;
	push(2, q1);
	push(4, q1);
	push(6, q1);
	push(8, q1);
	cout<<"Popped elemennt : "<<pop(q1);
	_getch();
	return 0;
}