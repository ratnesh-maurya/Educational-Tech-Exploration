//Program to find height of a BST
#include<iostream>
using namespace std;

int main()
{
  struct Node
  {
    int data;
    struct Node* left;
    struct Node* right;
  };
  
  int FindHeight(struct Node* root)
  {
    if(root == NULL)
      return -1;
    return max(FindHeight(root -> left), FindHeight(root -> right)) + 1;
  }
}
