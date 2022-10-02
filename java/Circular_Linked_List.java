/* Function to print nodes in a
given Circular linked list */
static void printList(Node head)
{
	Node temp = head;
	
	// If linked list is not empty
	if (head != null)
	{
		
		// Keep printing nodes till we reach the first node
		// again
		do
		{
			System.out.print(temp.data + " ");
			temp = temp.next;
		} while (temp != head);
	}
}
