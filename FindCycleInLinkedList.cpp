#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<algorithm>

using namespace std;

struct Node {
	Node* next;
	int data;
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

/*Floyd’s Cycle-Finding Algorithm*/
bool hasCycle(Node *head) {
	Node* slow_ptr = head; Node* fast_ptr = head;
	while (slow_ptr && fast_ptr && fast_ptr->next != NULL) {
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;
		if (slow_ptr == fast_ptr)
			return true;
	}
	return false;
}

int main()
{
	Node* head = NULL;
	Insert(&head, 2, 1);
	Insert(&head, 4, 2);
	Insert(&head, 7, 3);
	Insert(&head, 5, 4);
	Insert(&head, 8, 4);
	head->next->next->next->next = head;
	if(hasCycle(head))
		cout << "Linkedlist has a loop";
	else
		cout << "Linkedlist doesn't have loop";

	_getch();
	return 0;
}