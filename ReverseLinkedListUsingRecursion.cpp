#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

struct  Node
{
	int data;
	Node* next;
};

void Insert(Node** head, int data, int n)
{
	Node* current = new Node();
	current->data = data;
	current->next = NULL;
	if (n == 1)
	{
		current->next = *head;
		*head = current;
		return;
	}
	Node* prev = *head;
	for (int i = 0; i < n - 2; i++)
	{
		prev = prev->next;
	}
	current->next = prev->next;
	prev->next = current;
}

void reverseLinkedList(Node** head, Node* p)
{
	if (p->next == NULL)
	{
		*head = p;
		return;
	}
	reverseLinkedList(head, p->next);
	p->next->next = p;
	p->next = NULL;
}

int main()
{
	Node* head = NULL;
	Insert(&head, 2, 1);
	Insert(&head, 4, 2);
	Insert(&head, 3, 3);
	Insert(&head, 5, 4);
	Node* p = head;
	reverseLinkedList(&head, p);
	return 0;
	_getch();
}