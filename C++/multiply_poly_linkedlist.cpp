#include<bits/stdc++.h>
using namespace std;
struct Node{
    int coe,pow;
    Node* next;
};
Node* addnode(Node* start, int coe, int pow)
{
    // Create a new node
    Node* newnode = new Node;
    newnode->coe = coe;
    newnode->pow = pow;
    newnode->next = NULL;
  
    // If linked list is empty
    if (start == NULL)
        return newnode;
  
    // If linked list has nodes
    Node* ptr = start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = newnode;
  
    return start;
}
void printList(struct Node* ptr)
{
    while (ptr->next != NULL) {
        cout << ptr->coe << "x^" << ptr->pow ;
       if( ptr->next!=NULL && ptr->next->coe>=0)
          cout << "+";
  
        ptr = ptr->next;
    }
    cout << ptr->coe << "\n";
}
void removeDuplicates(Node* start)
{
    Node *ptr1, *ptr2, *dup;
    ptr1 = start;
  
    /* Pick elements one by one */
    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
  
        // Compare the picked element
        // with rest of the elements
        while (ptr2->next != NULL) {
  
            // If powerer of two elements are same
            if (ptr1->pow== ptr2->next->pow) {
  
                // Add their coefficients and put it in 1st element
                ptr1->coe = ptr1->coe + ptr2->next->coe;
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
  
                // remove the 2nd element
                delete (dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

Node* multiply(Node* poly1, Node* poly2, Node* poly3)
{
  
    // Create two pointer and store the address of 1st and 2nd polynomials
    Node *ptr1, *ptr2;
    ptr1 = poly1;
    ptr2 = poly2;
    
    while (ptr1 != NULL) {
        while (ptr2 != NULL) {
            int coeff, power;
            coeff = ptr1->coe * ptr2->coe;
            power = ptr1->pow+ ptr2->pow;
            poly3 = addnode(poly3, coeff, power);
            ptr2 = ptr2->next;
        }
        ptr2 = poly2;
        ptr1 = ptr1->next;
    }
    removeDuplicates(poly3);
    return poly3;
  
}
int main()
{
  
    Node *poly1 = NULL, *poly2 = NULL, *poly3 = NULL;
   poly1 = addnode(poly1, 45, 4);
    poly1 = addnode(poly1, 7, 3);
    poly1 = addnode(poly1, 8, 1);
    poly1 = addnode(poly1, -8, 0);
    
    poly2 = addnode(poly2, 6, 4);
    poly2 = addnode(poly2, 7, 3);
    poly2 = addnode(poly2, -5, 2);
    poly2 = addnode(poly2, 3, 1);
    poly2 = addnode(poly2, 3, 0);
  
    // Displaying 1st polynomial
    cout << "1st Polynomial:- ";
    printList(poly1);
  
    // Displaying 2nd polynomial
    cout << "2nd Polynomial:- ";
    printList(poly2);
  
    // calling multiply function
    poly3 = multiply(poly1, poly2, poly3);
  
    // Displaying Resultant Polynomial
    cout << "Resultant Polynomial:- ";
    printList(poly3);
  
    return 0;
}