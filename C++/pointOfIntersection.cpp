#include<iostream>
using namespace std;
class node{
    public:
     int data;
     node *next;
     node(int val){
        data=val;
        next=NULL;
     }
};
     void insertAtend(node *&head,int val){
        node *temp=new node(val);
        node *ptr=head;
        if (head==NULL)
        {
            head=temp;
            return ;
        }
        while (ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
        
        
     }
     void display(node * head){
        node *temp=head;
        while (temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
        
     }
     int length(node *head){
        node *temp=head;
        int l=0;
        while (temp!=NULL)
        {
            temp=temp->next;
            l++;
        }
        return l;
     }
     void intersect(node *head1,node *head2,int pos){
        node *temp1=head1;
        pos--; 
        while (pos--)
        {
            temp1=temp1->next;
        }
        node *temp2=head2;
        while (temp2->next!=NULL)
        {
            temp2=temp2->next;
        }
        temp2->next=temp1;
        
     }
     int pointOfIntersection(node *head1,node *head2){
        int l1=length(head1);
        int l2=length(head2);
        node *ptr1;
        node *ptr2;
        int d=0;
        if (l1>l2)
        {
            d=l1-l2;
            ptr1=head1;
            ptr2=head2;
        }
        else{
            d=l2-l1;
            ptr1=head2;
            ptr2=head1;
        }
        while (d)
        {    
            ptr1=ptr1->next;
            if (ptr1==NULL)
            {
                return -1;
            }
            d--;
        }
        while (ptr1!=NULL && ptr2!=NULL)
        {
            
            ptr1=ptr1->next;
            ptr2=ptr2->next;
            if (ptr1==ptr2)
            {
                return ptr1->data;
            } 
        }
        return -1;

     }
     int main(){
        node *head1=NULL;
        node *head2=NULL;
        
        insertAtend(head1,1);
        insertAtend(head1,2);
        insertAtend(head1,3);
        insertAtend(head1,4);
        insertAtend(head1,5);
        insertAtend(head1,6);
        insertAtend(head2,9);
        insertAtend(head2,10);
        intersect(head1,head2,3);
        cout<<pointOfIntersection(head1,head2);
       return 0;
     }