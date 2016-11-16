#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<algorithm>
#include<array>

int top = -1;
using namespace std;

void push(int x, int *A, int size) {
	if (top == size - 1) {
		cout << "Error: Stack Overflow";
		return;
	}
	top++;
	A[top] = x;
	//A[++top] = x;
}

void pop() {
	if (top == -1) {
		cout << "Error: Stack Empty";
		return;
	}
	top--;
}

int Top(int *A){
	return A[top];
}

void Print(int *A) {
	for (int i = 0; i <= top; i++) {
		cout << A[i] << "\n";
	}
}

int main()
{
	int size = 101;
	int *A = new int[size];
	push(2, A, size); Print(A);
	push(10, A, size); Print(A);
	push(5, A, size);Print(A);
	pop();Print(A);
	push(12, A, size);Print(A);
	_getch();
	return 0;
}
