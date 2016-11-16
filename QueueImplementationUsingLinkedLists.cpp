#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<algorithm>

using namespace std;
struct Node
{
	int data;
	Node* next;
};
Node* front = NULL; Node* rear = NULL;

void enQueue(int x) {
	Node* temp = new Node();
	temp->data = x;
	temp->next = NULL;
	if (front == NULL && rear == NULL) {
		front = rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}

void deQueue() {
	Node* temp = front;
	if (front == NULL) return;
	if (front == rear)front = rear = NULL;
	else front = front->next;
	delete temp;	
}

void Print() {
	Node* temp = front;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}

int main()
{
	enQueue(2); Print();
	enQueue(10); Print();
	enQueue(5);Print();
	deQueue();Print();
	enQueue(12);Print();
	_getch();
	return 0;
}

