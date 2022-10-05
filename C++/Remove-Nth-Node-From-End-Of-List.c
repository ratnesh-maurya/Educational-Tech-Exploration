//Leetcode Problem: 19. Remove Nth Node From End of List 

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    struct ListNode *fast, *slow;
    fast = slow = head;
    for (int i = 0; i < n; i++)
        fast = fast->next;

    if (fast == NULL)
        return head->next;

    fast = fast->next;
    while (fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return head;
}
