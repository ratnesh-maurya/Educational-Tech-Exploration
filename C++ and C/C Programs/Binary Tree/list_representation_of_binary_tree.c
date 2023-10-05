/* Represent a Binary Tree using a Linked List Data Structure in C
This code basically creates a binary tree using linked list nodes and establishes the relationships between the nodes to represent the tree's structure
*/

//include two standard header files
#include <stdio.h>  /* required for input and output operations */
#include <stdlib.h> /* dynamic memory allocation using malloc */

struct node /* It defines a structure called struct node, which represents a node in the binary tree */
{
    int data;
    struct node *left;  /* a pointer to another struct node, representing the left child of the current node */
    struct node *right; /* a pointer to another struct node, representing the right child of the current node */
};

struct node *createnode(int data) /* this function is defined to create a new node for the binary tree */
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node)); /* allocates memory for a new node using malloc */
    new_node->data = data; /* initializes the data of new node with the provided data (int the argument) */
    new_node->left = NULL; /* sets both the left and right pointers to NULL */
    new_node->right = NULL;
    return new_node; /*  Finally, it returns a pointer to the newly created node */
};

int main()
{
    struct node *p = createnode(5);
    struct node *p1 = createnode(3);
    struct node *p2 = createnode(6);
    struct node *p3 = createnode(2);
    struct node *p4 = createnode(8);

    /* Here, we create five nodes p, p1, p2, p3, and p4 using the createnode function, and assigns them values as follows:
    p represents the root node with data 5.
    p1 represents the left child of p with data 3.
    p2 represents the right child of p with data 6.
    p3 represents the left child of p1 with data 2.
    p4 represents the right child of p1 with data 8.

    The binary tree looks something like this:
                5
               / \
              3   6
             / \
            2   8
    */

    /* To represent this structure, we link the nodes together by assigning the appropriate left and right pointers */
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    return 0;
}