#include<iostream>
using namespace std;

int main()
{
  struct BSTNode
  {
    int data;
    BSTNode* left;
    BSTNode* right;
  };

  //iterative solution
  int FindMin(BSTNode* root)
  {
    if(root == NULL)
    {
      cout << "Error: Tree is empty" << endl;
      return -1;
    }
    BSTnode* current = root;  //Ideally, we can use 'root' instead of 'current'
    while(current -> left != NULL)
    {
      current = current -> left;
    }
    return current -> data;
  }
  
  //iterative solution for finding max element
  int FindMax(BSTNode* root)
  {
    if(root == NULL)
    {
      cout << "Error: Tree is empty" << endl;
      return -1;
    }
    BSTnode* current = root;  //Ideally, we can use 'root' instead of 'current'
    while(current -> right != NULL)
    {
      current = current -> right;
    }
    return current -> data;
  }
}
