public class ReverseLLrecursive {
   
    class ListNode {
        int val;
         ListNode next;
         ListNode() {}
         ListNode(int val) { this.val = val; }
         ListNode(int val, ListNode next) { this.val = val; this.next = next; }
     }
    
   
    public static ListNode reverseLinkedListRec(ListNode head) {
        if ( head==null || head.next==null){
            return head;
        }
        ListNode reversNode=head.next;
        ListNode ans = reverseLinkedListRec(head.next);
        reversNode.next=head;
        head.next=null;
        return ans;
    }
}
