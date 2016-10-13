#include<iostream>
#include<conio.h>
#include<stdio.h>

using namespace std;

struct  Node
{
	int data;
	Node* next;
};

int length(Node* head)
{
	int len = 0;
	while (head != NULL)
	{
		head = head->next;
		len++;
	}
	return len;
}


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

Node* mergeTwoLists(Node* A, Node* B)
{
	Node* listA = A; Node* listB = B;
	Node* sortedList = new Node();
	int sizeA, sizeB;
	while (listA != NULL && listB != NULL)
	{
		if (listA->data < listB->data)
		{
			sortedList->data = listA->data;
			sortedList = sortedList->next;
			listA = listA->next;
			sizeA++;
		}
		else if (listA->data > listB->data)
		{
			sortedList->data = listB->data;
			sortedList = sortedList->next;
			listB = listB->next;
			sizeB++;
		}
		else
		{
			sortedList->data = listA->data;
			sortedList = sortedList->next;
			listA = listA->next;
			listB = listB->next;
			sizeA++; sizeB++;
		}
	}

	/*add the remaining items fro either list*/
	if (sizeA != length(A))
	{
		for (int i = 0; i < length(A) - sizeA; i++)
		{
			sortedList->data = listA->data;
			sortedList = sortedList->next;
			listA = listA->next;
		}
	}
	else if (sizeB != length(B))
	{
		for (int i = 0; i < length(A) - sizeA; i++)
		{
			sortedList->data = listB->data;
			sortedList = sortedList->next;
			listB = listB->next;			
		}
	}
	return sortedList;
}

int main()
{
	Node* head1 = NULL;
	Insert(&head1, 2, 1);
	Insert(&head1, 4, 2);
	Insert(&head1, 9, 3);
	Insert(&head1, 12, 4);

	Node* head2 = NULL;
	Insert(&head2, 3, 1);
	Insert(&head2, 6, 2);
	Insert(&head2, 7, 3);
	Insert(&head2, 11, 4);

	Node *result = mergeTwoLists(head1, head2);
	_getch();
	return 0;
}