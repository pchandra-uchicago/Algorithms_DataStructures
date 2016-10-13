#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

struct  Node {
	int data;
	Node* next;
};
/* inserts node at Nth position*/
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
/* delete node at Nth position*/
void Delete(Node** head, int n) {
	if (n == 1) {
		Node* temp = *head;
		*head = temp->next;
		delete temp;
		return;
	}
	Node *current = *head;
	for (int i = 0; i < n - 2; i++)	{
		current = current->next;
	}
	Node *temp = current->next;
	current->next = temp->next;
	delete temp;
}

void Print(Node* head) {
	Node * current = head;	
	while (current != NULL)	{
		cout << current->data << '\t';
		current = current->next;
	}
}

int main()
{
	Node* head = NULL;
	Insert(&head, 2, 1);
	Insert(&head, 4, 2);
	Insert(&head, 7, 1);
	Insert(&head, 5, 4);	
	Insert(&head, 8, 3);
	Insert(&head, 9, 2);
	cout << "The list after insertion is : ";
	Print(head);
	cout << "\n\n";
	Delete(&head, 1);
	cout << "The list after deletion is : ";
	Print(head);
	_getch();
	return 0;
}
