#include<iostream>
#include<conio.h>
#include<stdio.h>

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

Node* rotateRight(Node* A, int B)
{
	if (B == 0)
		return A;
	if (B>length(A))
	{
		B = B % length(A);
	}

	Node* rotatedList= A; 
	for (int i = 0; i < B; i++) 
	{
		rotatedList = rotatedList->next;
	}

	Node* rotatedHead = rotatedList;
	Node* temp = A;
	for (int i = 1; i <= B; i++)
	{
		/*insert the nodes at the end*/
		Insert(&rotatedHead, temp->data, length(rotatedHead)+1);
		temp = temp->next;
	}	
	return rotatedHead;
}

int main()
{
	Node *head = NULL;
	Insert(&head, 2, 1);
	Insert(&head, 4, 2);
	Insert(&head, 7, 3);
	Insert(&head, 5, 4);	

	Node* temp = rotateRight(head, 3);
	_getch();
	return 0;
}