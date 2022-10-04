

class ListNode {
    int val;
     ListNode next;
     ListNode() {}
     ListNode(int val) { this.val = val; }
     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 }

public class RemoveDuplicatesLL {


    public static ListNode eleNode(ListNode head){
        ListNode current = head;
        while (current != null) {
            if(current.next != null && current.val == current.next.val)
                current.next = current.next.next;
            else
                current = current.next;
        }
        return head;
    
}
}