import java.util.*;

class ListNode {
    int val;
     ListNode next;
     ListNode() {}
     ListNode(int val) { this.val = val; }
     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 }

public class LinkedListCycle {
    public boolean hasCycle(ListNode head) {
        var nodesTracker = new HashSet<ListNode>();
   while(head != null){
       if(nodesTracker.contains(head)){
           return true;
       }
       nodesTracker.add(head);
       head = head.next;
   }
   return false;

}

}
