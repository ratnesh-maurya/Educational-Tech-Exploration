#include "iostream"
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution{
    
  private:
  Node* getMiddle(Node* head){
      Node* slow = head;
      Node* fast = head -> next;
      
      while(fast != NULL && fast -> next != NULL){
          fast = fast -> next -> next;
          slow = slow -> next;
      }
      return slow;
  }
  
  Node* reverse(Node* head){
      Node* curr = head;
      Node* prev = NULL;
      Node* forw = NULL;
      
      while(curr != NULL){
          forw = curr -> next;
          curr -> next = prev;
          prev = curr;
          curr = forw;
      }
      return prev;
  }
    
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        
        if(head -> next == NULL){
            return true;
        }
        Node* middle = getMiddle(head);
        
        Node* temp = middle -> next;
        middle -> next = reverse(temp);
        
        Node* head1 = head;
        Node* head2 = middle -> next;
        while(head2 != NULL){
            if(head1 -> data == head2 -> data){
                head1 = head1 -> next;
                head2 = head2 -> next;
            }
            else{
                return false;
            }
        }
        return true;
        
    }
};