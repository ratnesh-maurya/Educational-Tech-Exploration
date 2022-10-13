#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,x,y) for(ll i=x;i<y;i++)


class Node
{
public:
    int data;
    Node* left=NULL;
    Node* right=NULL;
    Node(int x)
    {
        data=x;
    }
};

bool Find(Node* head, int a, int b)
{
    if(head==NULL) return false;
    if(head->data==a || head->data==b) return true;
    else return Find(head->left,a,b)||Find(head->right,a,b);
}

int LowestCommonAncestor(Node* head,int a,int b)
{
    if(head==NULL) return -1;
    if(head->data==a || head->data==b) return head->data;
    else if(Find(head->left,a,b) && Find(head->right,a,b)) return head->data;
    else if(Find(head->left,a,b)) return LowestCommonAncestor(head->left,a,b);
    else if(Find(head->right,a,b)) return LowestCommonAncestor(head->right,a,b);
    return -1;
}

int main()
{
    Node* head=new Node(1);
    head->left=new Node(2);
    head->right=new Node(3);
    head->left->left=new Node(4);
    head->left->right=new Node(5);
    head->right->left=new Node(6);
    head->right->right=new Node(7);
    head->left->left->right=new Node(8);
    head->left->right->left=new Node(9);
    head->right->left->left=new Node(10);
    head->right->right->right=new Node(11);
    head->right->right->right->right=new Node(12);

    int a = 6, b = 12;
    cout<<LowestCommonAncestor(head,a,b);
    
    return 0;
}