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

Node* deleteDuplicates(Node* A)
{
	Node* head = A; 
	while (head!= NULL)
	{
		while (head->next != NULL && head->data == head->next->data)
		{
			head->next = head->next->next;
		}
		head = head->next;
	}
	return A;	
}

int main()
{
	Node* head = NULL;
	Insert(&head, 2, 1);
	Insert(&head, 4, 2);
	Insert(&head, 3, 3);
	Insert(&head, 3, 4);
	Node* result = deleteDuplicates(head);
	return 0;
}