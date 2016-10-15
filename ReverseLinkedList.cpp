#include<iostream>
#include<conio.h>
#include<stdio.h>

using namespace std;
struct  Node {
	int data;
	Node* next;
};

void Insert(Node** head, int data, int n) {
	Node* current = new Node();
	current->data = data;
	current->next = NULL;
	if (n == 1) {
		current->next = *head;
		*head = current;
		return;
	}
	Node* prev = *head;
	for (int i = 0; i < n - 2; i++)	{
		prev = prev->next;
	}
	current->next = prev->next;
	prev->next = current;
}

/* iterative method*/
Node* reverseLinkedList(Node* A) {
	Node* current; Node* prev = NULL; Node* next; Node* head = A;
	current = head;
	while (current != NULL)	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	return head;
}

int main()
{
	Node* head1 = NULL;
	Insert(&head1, 2, 1);
	Insert(&head1, 4, 2);
	Insert(&head1, 7, 3);

	Node* temp = reverseLinkedList(head1);
	_getch();
	return 0;
}
