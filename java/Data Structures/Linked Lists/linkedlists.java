class sinlgyLinkedList {
  static Node head;

  static class Node {
    int data;
    Node next;

    Node(int d) {
      this.data = d;
      next = null;
    }
  }

  // https://www.youtube.com/watch?v=ugQ2DVJJroc
  Node IterativeReverse(Node head) {
    Node prev = null;
    Node current = head;
    Node temp = null; // temp is used to store the next node
    while (current != null) {
      temp = current.next;
      current.next = prev;

      prev = current;
      current = temp;
    }
    head = prev;
    return head;
  }

  Node recursiveReverse(Node head) {
    // null - head  - headNext - newHead
    if (head == null || head.next == null) return head;
    Node newHead = recursiveReverse(head.next);
    /*
     * head.next.next = head;
     */
    // from here
    Node headNNEXT = head.next;
    headNNEXT.next = head;
    // to here is the same as above
    head.next = null;
    return newHead;
  }

  // loop detection with floyd algorithm(slow pointer and fast pointer, if the
  // meet[loop found] else no loop found)
  // O(N), aux-> O(1);
  int detectloop() {
    Node slow_p = head, fast_p = head;

    while (slow_p != null && fast_p != null) {
      slow_p = slow_p.next;
      fast_p = fast_p.next.next;
      if (slow_p == fast_p) {
        return 1;
      }
    }
    return 0;
  }

  // function to remove loop
  void removeLoop(Node loop, Node head) {
    Node ptr1 = loop;
    Node ptr2 = loop;

    // count the number of nodes in loop;
    int k = 1, i;
    while (ptr1.next != ptr2) {
      ptr1 = ptr1.next;
      k++;
    }
    ptr1 = head; // fix the one pointer to head
    ptr2 = head; // and the other pointer to k niodes after head
    for (i = 0; i < k; i++) {
      ptr2 = ptr2.next;
    }
    while (ptr2 != ptr1) {
      ptr1 = ptr1.next;
      ptr2 = ptr2.next;
    }
  }

  void detectAndRemoveLoop(Node head) {
    if (head == null || head.next == null) return;

    Node slow = head, fast = head;

    slow = slow.next;
    fast = fast.next.next;
    // searching for loops actually
    while (fast != null && fast.next != null) {
      if (slow == fast) {
        break;
      }
      slow = slow.next;
      fast = fast.next.next;
    }
    // if loop exits
    if (slow == fast) {
      slow = head;
      if (slow != fast) {
        while (slow.next != fast.next) {
          slow = slow.next;
          fast = fast.next;
        }
        // since fast.next is the looping point
        fast.next = null; // remove the loop
      } else {
        while (fast.next != slow) {
          fast = fast.next;
        }
        fast.next = null;
      }
    }
  }

  // merge sort on linkedlist
  // time O(n log n) space O(logn)
  static Node mergeSort(Node head) {
    if (head.next == null) return head;

    Node mid = getMid(head);
    Node head2 = mid.next;
    mid.next = null; // break linkedlist
    Node newHead1 = mergeSort(head);
    Node newHead2 = mergeSort(head2);
    Node finalHead = merge(newHead1, newHead2);
  }

  static Node merge(Node head1, Node head2) {
    Node merged = new Node(-1);
    Node temp = merged;

    // while both lists are not empty
    while (head1 != null && head2 != null) {
      if (head1.data < head2.data) {
        temp.next = head1;
        head1 = head1.next;
      } else {
        temp.next = head2;
        head2 = head2.next;
      }
      temp = temp.next;
    }

    while (head1 != null) {
      temp.next = head1;
      head1 = head1.next;
      temp = temp.next;
    }
    while (head2 != null) {
      temp.next = head2;
      head2 = head2.next;
      temp = temp.next;
    }

    return merged.next;
  }

  static Node getMid(Node hear) {
    Node slow = head;
    Node fast = head;
    while (fast.next != null && fast.next.next != null) {
      slow = slow.next;
      fast = fast.next.next;
    }
    return slow;
  }
}
// fastest method is to use Hashmap and Hashset in it
