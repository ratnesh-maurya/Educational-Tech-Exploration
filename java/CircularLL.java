package linkedlist.circular_ll;
import java.util.*;

public class CircularLL{
	class node{
		int data;
		node next;
		
		node(int d){
			next=null;
			data=d;
		}
	}
	
	node head;
	
	public node CreateCLL(){
		Scanner scan = new Scanner(System.in);
		int data,cont=1;
		node temp=head;
		while(cont==1){
			System.out.println("Enter the data you want to insert : ");
			data = scan.nextInt();
			node newNode= new node(data);
			if(head==null){
				temp = head=newNode;
				newNode.next=head;
			}
			else{
				temp.next = newNode;
				temp = temp.next;
				newNode.next=head;
			}
			System.out.println("Do you want to continue? 0.no 1.yes ");
			cont=scan.nextInt();
			if(cont==0){
				break;
			}		}
		return head;
	}

	public void InsertAtBeg(int num){
		node temp=head;
		node NewNode=new node(num);
		while(temp.next!=head){
			temp=temp.next;
		}
		NewNode.next=head;
		head=NewNode;
		temp.next=NewNode;
		System.out.println(num+" is inserted at start of the list.");
	}

	public void InsertAtPos(int pos,int num){
		node temp=head,temp1=head;
		node NewNode = new node(num);
		int maxitems = validatePos(pos),i=1;
		
		if(pos<1 || pos>=maxitems){
			System.out.println("Invalid Position");
		}
		else{
			if(pos==1){
				head = NewNode;
				pos=maxitems;
			}
			
			while(i<pos){
				temp1=temp;
				temp=temp.next;
				i++;
			}

			temp1.next=NewNode;
			NewNode.next=temp;
			System.out.println(num+" is inserted at "+pos+" position of the list.");
		}
	}

	

	public void InsertAtEnd(int datai){
		Scanner sc = new Scanner(System.in);
		node temp = head;
		int data = datai;
		node newnode=new node(data);

		if(temp==null){
			head=newnode;
		}
		else{
			while(temp.next!=head){
				temp = temp.next;
			}
			newnode.next=head;
			temp.next=newnode;
		}
		System.out.println(data+" is insrted at end of the list.");
	}

	public int validatePos(int pos){
		node temp=head.next;
		int items=1;

		if(head==null){
			items=1;
		}
		else{
			while(temp!=head){
				items++;
				temp=temp.next;
			}
		}
		
		return items;
	}

	//
	public void Delete(int pos){
		int maxNum = validatePos(pos);
		if(pos<1 || pos>maxNum){
			System.out.println("Invalid Position : Please enter a valid position.");		
		}
		else{
			int item=1,realpos=pos;
			node temp=head,temp1=head;
		
			if(pos==1){
				realpos=pos;
				pos=maxNum+1;
				head=head.next;
			}
		
			while(item<pos){
				item++;
				temp1=temp;
				temp=temp.next;
			}
			temp1.next=temp.next;
			System.out.println(temp.data+" is deleted from "+realpos+" position");
		}
		
	}

	public void display(){
		node temp=head;
		System.out.println("List after adding nodes at the end :");
		if(head==null){
			System.out.println("List is empty..");
		}
		else if(head.next==head){
			System.out.println(temp.data);
		}
		else{
			while(temp.next!=head){
				System.out.print(temp.data+" ");
				temp=temp.next;
			}
			System.out.print(temp.data+" ");
		}
	}
}