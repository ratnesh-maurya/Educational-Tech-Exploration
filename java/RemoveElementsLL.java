public class RemoveElementsLL {
    class ListNode {
        int val;
         ListNode next;
         ListNode() {}
         ListNode(int val) { this.val = val; }
         ListNode(int val, ListNode next) { this.val = val; this.next = next; }
     }

    public ListNode removeElements(ListNode head, int val) {
        ListNode x = delete(head, val);
        if(x != null && x.val == val)
            return x.next;
        return x;
    }
    public ListNode delete(ListNode head, int val){
        if(head == null || head.next == null)
            return head;
        ListNode temp = removeElements(head.next, val);
        if(head.next.val == val)
            head.next = head.next.next;
        return head;
    }

}
