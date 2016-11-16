#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<algorithm>

using namespace std;
const int N = 100;
int front = -1, rear = -1;

bool isEmpty()
{
	if (front == -1 && rear == -1) return true;
	else return false;
}

void enQueue(int x, int *A)
{
	if ((rear+1)%N == front)	return;
	else if (isEmpty())
		front = rear = 0;
	else  rear = (rear + 1)%N;
	A[rear] = x;
}

void deQueue()
{
	if (isEmpty()) return;
	else if (front == rear)	front = rear = -1;
	else front = (front + 1)%N;	
}

void Print(int *A)
{
	for (int i = front; i <= rear; i++) {
		cout << A[i] << "\n";
	}
}

int main()
{
	int *A = new int[N];
	enQueue(2, A); Print(A);
	enQueue(10, A); Print(A);
	enQueue(5, A);Print(A);
	deQueue();Print(A);
	enQueue(12, A);Print(A);
	_getch();
	return 0;
}