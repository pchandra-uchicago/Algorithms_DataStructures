#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>

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

Node* addTwoNumbers(Node* A, Node* B)
{
	Node* listA = A; Node* listB = B;
	vector<string> strA; vector<string> strB;
	while (listA || listB)
	{
		if (listA)
		{
			strA.push_back(to_string(listA->data));
			listA = listA->next;
		}
		if (listB)
		{
			strB.push_back(to_string(listB->data));
			listB = listB->next;
		}		
	}
	std::reverse(strA.begin(), strA.end());
	std::reverse(strB.begin(), strB.end());

	string sum = to_string(stoi(accumulate(strA.begin(), strA.end(), string(""))) + 
							stoi(accumulate(strB.begin(), strB.end(), string(""))));
	reverse(sum.begin(), sum.end());

	Node* head = NULL;
	for (int i = 0; i < sum.size(); i++)
	{
		Node* current = new Node();
		current->data = (int)(sum.at(i)) - 48;
		current->next = NULL;
		if (i == 0)
			head = current;
		else
		{
			Node* prev = head;
			while (prev->next != NULL)
			{
				prev = prev->next;
			}
			prev->next = current;
		}		
	}
	return head;
}

int main()
{
	Node* head1 = NULL;
	Insert(&head1, 2, 1);
	Insert(&head1, 4, 2);
	Insert(&head1, 7, 3);	

	Node* head2 = NULL;
	Insert(&head2, 3, 1);
	Insert(&head2, 6, 2);
	Insert(&head2, 7, 3);	

	Node* temp = addTwoNumbers(head1, head2);
	_getch();
	return 0;
}