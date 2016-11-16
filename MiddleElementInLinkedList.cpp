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
	for (int i = 0; i < n - 2; i++) {
		prev = prev->next;
	}
	current->next = prev->next;
	prev->next = current;
}

Node* middleElement(Node* head) {
	Node* slow_ptr = head; Node* fast_ptr = head; int count = 0;
	if (head != NULL) {
		while (fast_ptr != NULL && fast_ptr->next != NULL) {
			slow_ptr = slow_ptr->next;
			fast_ptr = fast_ptr->next->next;
			count++;
		}
	}
	return slow_ptr;
}

int main()
{
	Node* head = NULL;
	Insert(&head, 2, 1);
	Insert(&head, 4, 2);
	Insert(&head, 7, 3);
	Insert(&head, 5, 4);
	Insert(&head, 8, 4);
	Node* temp = middleElement(head);
	_getch();
	return 0;
}
