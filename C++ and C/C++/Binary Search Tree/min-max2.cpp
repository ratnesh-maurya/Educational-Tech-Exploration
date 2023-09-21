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

  //recursive solution
  int FindMin(BSTNode* root)
  {
    if(root == NULL)
    {
      cout << "Error: Tree is empty" << endl;
      return -1;
    }
    else if(root -> left != NULL)
    {
      root -> data;
    }
    return FindMin(root -> left);
  }
    
  //recursive solution to find Max element in a BST
  int FindMax(BSTNode* root)
  {
    if(root == NULL)
    {
      cout << "Error: Tree is empty" << endl;
      return -1;
    }
    else if(root -> right != NULL)
    {
      root -> data;
    }
    return FindMax(root -> right);
  }
}
