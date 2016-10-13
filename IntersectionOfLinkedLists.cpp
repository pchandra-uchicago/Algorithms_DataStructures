#include<iostream>
#include<conio.h>
#include<stdio.h>

using namespace std;
struct  Node {
	int data;
	Node* next;
};
int length(Node* head) {
	int len = 0;
	while (head != NULL) {
		head = head->next;
		len++;
	}
	return len;
}
Node* getIntersectionNode(Node* listA, Node* listB) {
	int m = length(listA);
	int n = length(listB);
	if (m > n) {
		int d = m - n;
		for (int i = 0; i < d; i++) {
			listA = listA->next;
		}
	}
	else if (n > m)	{
		int d = n - m;
		for (int i = 0; i < d; i++) {
			listB = listB->next;
		}
	}	
	while (listA != NULL && listB != NULL) {
		if (listA->data == listB->data)	{
			return listA;
		}		
		listA = listA->next;
		listB = listB->next;
	}
	return NULL;
}
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
int main()
{
	Node* head1 = NULL;
	Insert(&head1, 2, 1);
	Insert(&head1, 4, 2);
	Insert(&head1, 7, 3);
	Insert(&head1, 5, 4);

	Node* head2 = NULL;
	Insert(&head2, 3, 1);
	Insert(&head2, 6, 2);
	Insert(&head2, 7, 3);
	Insert(&head2, 5, 4);

	Node* temp = getIntersectionNode(head1, head2);
	_getch();
	return 0;
}
