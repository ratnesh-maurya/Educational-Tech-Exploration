// C++ program for merge sort on doubly linked list
#include <bits/stdc++.h>
using namespace std;
class Node
{
	public:
	int data;
	Node *next, *prev;
};

Node *split(Node *head);
Node *merge(Node *first, Node *second)
{
	if (!first)
		return second;
	if (!second)
		return first;

	// Pick the smaller value
	if (first->data < second->data)
	{
		first->next = merge(first->next,second);
		first->next->prev = first;
		first->prev = NULL;
		return first;
	}
	else
	{
		second->next = merge(first,second->next);
		second->next->prev = second;
		second->prev = NULL;
		return second;
	}
}
Node *mergeSort(Node *head)
{
	if (!head || !head->next)
		return head;
	Node *second = split(head);

	// Recur for left and right halves
	head = mergeSort(head);
	second = mergeSort(second);

	// Merge the two sorted halves
	return merge(head,second);
}

void insert(Node **head, int data)
{
	Node *temp = new Node();
	temp->data = data;
	temp->next = temp->prev = NULL;
	if (!(*head))
		(*head) = temp;
	else
	{
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}

void print(Node *head)
{
	Node *temp = head;
	cout<<"Forward Traversal using next pointer\n";
	while (head)
	{
		cout << head->data << " ";
		temp = head;
		head = head->next;
	}
	cout << "\nBackward Traversal using prev pointer\n";
	while (temp)
	{
		cout << temp->data << " ";
		temp = temp->prev;
	}
}

// Utility function to swap two integers
void swap(int *A, int *B)
{
	int temp = *A;
	*A = *B;
	*B = temp;
}

Node *split(Node *head)
{
	Node *fast = head,*slow = head;
	while (fast->next && fast->next->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	Node *temp = slow->next;
	slow->next = NULL;
	return temp;
}

// Driver program
int main(void)
{
	Node *head = NULL;
	insert(&head, 5);
	insert(&head, 20);
	insert(&head, 4);
	insert(&head, 3);
	insert(&head, 30);
	insert(&head, 10);
	head = mergeSort(head);
	cout << "Linked List after sorting\n";
	print(head);
	return 0;
}

