/*
Link: "https://leetcode.com/problems/merge-two-sorted-lists/"
21. Merge Two Sorted Lists
Easy
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.
Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
*/

class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
       ListNode head = new ListNode();
       ListNode tail = head;
        while(list1 != null && list2 != null){
            if(list1.val < list2.val){
                tail.next = list1;
                list1 = list1.next;
                tail = tail.next;
            }
          else{
                tail.next = list2;
                list2 = list2.next;
                tail = tail.next;
            }
        }
        
        while(list1 != null){
            tail.next = list1;
            list1 = list1.next;
            tail = tail.next;
        }
        while(list2 != null){
             tail.next = list2;
             list2 = list2.next;
             tail = tail.next;
        }
        
        return head.next;
    }
}
