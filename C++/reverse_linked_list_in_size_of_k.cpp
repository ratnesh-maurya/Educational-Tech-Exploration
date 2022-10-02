// CPP program to reverse a linked list
// in groups of given size
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node {
public:
	int data;
	Node* next;
};

/* Reverses the linked list in groups
of size k and returns the pointer
to the new head node. */
Node* reverse(Node* head, int k)
{
	// If head is NULL or K is 1 then return head
	if (!head || k == 1)
		return head;

	Node* dummy = new Node(); // creating dummy node
	dummy->data = -1;
	dummy->next = head;

	// Initializing three points prev, curr, next
	Node *prev = dummy, *curr = dummy, *next = dummy;

	// Calculating the length of linked list
	int count = 0;
	while (curr) {
		curr = curr->next;
		count++;
	}

	// Iterating till next is not NULL
	while (next) {
		// Curr position after every reverse group
		curr = prev->next;
		// Next will always next to curr
		next = curr->next;
		// toLoop will set to count - 1 in case of remaining
		// element
		int toLoop = count > k ? k : count - 1;
		for (int i = 1; i < toLoop; i++) {
			// 4 steps as discussed above
			curr->next = next->next;
			next->next = prev->next;
			prev->next = next;
			next = curr->next;
		}
		// Setting prev to curr
		prev = curr;
		// Update count
		count -= k;
	}
	// dummy -> next will be our new head for output linked
	// list
	return dummy->next;
}

/* UTILITY FUNCTIONS */
/* Function to push a node */
void push(Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node = new Node();

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print linked list */
void printList(Node* node)
{
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
}

/* Driver code*/
int main()
{
	/* Start with the empty list */
	Node* head = NULL;

	/* Created Linked list
	is 1->2->3->4->5->6->7->8->9 */
	push(&head, 9);
	push(&head, 8);
	push(&head, 7);
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);

	cout << "Given linked list \n";
	printList(head);
	head = reverse(head, 3);

	cout << "\nReversed Linked list \n";
	printList(head);

	return (0);
}


