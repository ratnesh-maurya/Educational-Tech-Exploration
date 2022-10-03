// Floyd’s Cycle-detection Algorithm 

// APPROACH --> 
// 1) Traverse the linked list using two pointers (slow and fast).
// 2) move the slow pointer by one and fast pointer by two.
// 3) If these pointers meet at the same node then there is a loop. If pointers do not meet then linked list doesn’t have a loop.

// TIME COMPLEXITY --> O(N)
// SPACE COMPLEXITY --> O(1)

#include <bits/stdc++.h>
using namespace std;
// linked list node
class Node {
public:
    int data;
    Node* next;
};
// function to push nodes in linked list 
void push(Node** head_ref, int new_data)
{

    Node* new_node = new Node();

    new_node->data = new_data;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}
// function to detect the loop 
int detectLoop(Node* list)
{
    Node *slow_p = list, *fast_p = list;

    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p) {
            return 1;
        }
    }
    return 0;
}
// driver code
int main()
{
    Node* head = NULL;

    push(&head, 30);
    push(&head, 10);
    push(&head, 5);
    push(&head, 6);

    // creating a loop for testing whether my algo is working or not.
    head->next->next->next->next = head;
    if (detectLoop(head))
        cout << "Loop found";
    else
        cout << "No Loop";
    return 0;
}