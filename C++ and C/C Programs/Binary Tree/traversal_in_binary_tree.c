/* Demonstrates three different binary tree traversal methods (preorder, inorder, and postorder) on a binary tree represented using linked list nodes.
This code provides a clear demonstration of how to create a binary tree using linked list nodes and how to perform different types of tree traversals using recursion. The output of the program will display the data of the nodes in the specified traversal orders. */

// include two standard header files
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
    return new_node; /* Finally, it returns a pointer to the newly created node */
};

void preorder_traversal(struct node *root) /* This function performs a preorder traversal of the binary tree, which means it visits the current node, then its left subtree, and finally its right subtree */
{
    if (root != NULL)
    {
        printf("%d, ", root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
};
void inorder_traversal(struct node *root) /* This function performs a postorder traversal, visiting the left subtree, then the right subtree, and finally the current node */
{
    if (root != NULL)
    {
        inorder_traversal(root->left);
        printf("%d, ", root->data);
        inorder_traversal(root->right);
    }
}

void postorder_traversal(struct node *root) /* This function performs an inorder traversal, visiting the left subtree, then the current node, and finally the right subtree */
{
    if (root != NULL)
    {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d, ", root->data);
    }
}

/* Each of these traversal functions is implemented using recursion, where it checks if the current node is not NULL, prints the data of the current node, and then recursively calls itself on the left and right subtrees */

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

    /* We then call each of the traversal functions to print the data in the binary tree */
    printf("\nPreorder traversal of the given binary tree is: ");
    preorder_traversal(p);
    printf("\n");
    printf("\nInorder traversal of the given binary tree is: ");
    inorder_traversal(p);
    printf("\n");
    printf("\nPostorder traversal of the given binary tree is: ");
    postorder_traversal(p);

    return 0;
}