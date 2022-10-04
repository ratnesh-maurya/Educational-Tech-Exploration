/*
Link: "https://leetcode.com/problems/remove-nth-node-from-end-of-list/"
19. Remove Nth Node From End of List
Medium
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
*/

class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        
        if(head == null)
            return head;
        if(head.next == null)
            return null;
        
        ListNode fast = head;
        ListNode slow = head;
        
        while(n>0)
        {
            fast = fast.next;
            n--;
        }
        if(fast==null)
        {
            return head.next;
        }
        
        while(fast.next!=null)
        {
            fast = fast.next;
            slow = slow.next;
        }
        if(slow.next.next!=null)
        {
            slow.next = slow.next.next;
        }
        else
        {
            slow.next = null;
        }
        return head;
    }
}
