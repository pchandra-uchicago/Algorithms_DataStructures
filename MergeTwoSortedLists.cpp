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

Node* mergeTwoLists(Node* A, Node* B) {
	if (A == NULL) return B;
	if (B == NULL) return A;

	Node* listA = A; Node* listB = B; Node* sortedHead = NULL;	
	if (listA->data < listB->data) {
		sortedHead = listA;
		listA = listA->next;
	}
	else {
		sortedHead = listB;
		listB = listB->next;
	}
	Node* sortedList = sortedHead;
	while (listA != NULL && listB != NULL) {
		if (listA->data < listB->data) {
			sortedList->next = listA;							
			listA = listA->next;			
		}
		else {
			sortedList->next = listB;							
			listB = listB->next;			
		}
		sortedList = sortedList->next;
	}	
	/*add the leftover elements*/
	if (listA)
		sortedList->next = listA;	
	else 
		sortedList->next = listB;	
	return sortedHead;
}

int main()
{
	Node* head1 = NULL;
	Insert(&head1, 2, 1);
	Insert(&head1, 4, 2);	

	Node* head2 = NULL;
	Insert(&head2, 3, 1);
	Insert(&head2, 6, 2);
	
	Node *result = mergeTwoLists(head1, head2);
	_getch();
	return 0;
}

