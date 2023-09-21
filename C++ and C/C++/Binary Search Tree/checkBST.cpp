//This approach is easy to think of but is not so efficient
//For the right subtree, find minimum and for left, find maximum

#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* left;
  Node* right;
};

bool IsSubtreeLesser(Node* root, int value)
{
  //traverse complete tree or subtree
  if(root == NULL)
    return true;
  if(root -> data <= value && IsSubtreeLesser(root -> left, value) && IsSubtreeLesser(root -> right, value))
    return true;
  else
    return false;
}

bool IsSubtreeGreater(Node* root, int value)
{
  //traverse complete tree or subtree
  if(root == NULL)
    return true;
  if(root -> data > value && IsSubtreeLesser(root -> left, value) && IsSubtreeLesser(root -> right, value))
    return true;
  else
    return false;
}

bool IsBST(Node* root)
{
  //return true if BST, false otherwise
  if(root == NULL)
    return true;
  if(IsSubtreeLesser(root -> left, root -> data) && IsSubtreeGreater(root ->right, root -> data) && IsBST(root ->left) && IsBST(root ->right))
    return true;
  else
    return false;
}
     
int main()
{
  //IsBST(200);
  //IsSubtreeLesser(150, 7);
  //IsSubtreeGreater(300, 7);
  //Take arguments according to the example
}
