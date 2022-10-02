// 142. Linked List Cycle II
#include<bits/stdc++.h>
using namespace std;

class ListNode {
    public:
        int data;
        ListNode* next;

    public:
        ListNode(int data){
            this->data = data;
            this->next = NULL;
        }
};

ListNode *detectCycle(ListNode *head) {
    
    if(head == NULL || head->next == NULL) {
        return head;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            slow = head;                        // there is a cycle
            while(slow != fast) {               // found the entry location
                slow  = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }

    return nullptr;
}