#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node* next;
};
typedef struct node Node;

bool b_search(Node** st,int target)
{
    Node* temp;
    temp = *st;
    while(temp!=NULL)
    {
        if (temp->data==target)
        {
            return true;
        }
        else if(temp->data<target)
        {
            temp = temp->next;
        }
        else{
            return false;
        }   
    }
    return false;
}

int main()
{
    Node* start;
    Node* temp;
    int ans;
    int target;
    start = (Node*)malloc(sizeof(Node));
    printf("Enter the data :");
    scanf("%d",&start->data);
    start->next = NULL;
    temp = start;
    printf("\nDo you want to enter another node(1 for yes any other number to exit) :");
    scanf("%d",&ans);
    while (ans==1)
    {
        temp->next = (Node*)malloc(sizeof(Node));
        temp = temp->next;
        printf("Enter the data :");
        scanf("%d",&temp->data);
        temp->next=NULL;
        printf("\nDo you want to enter another node(1 for yes any other number to exit) :");
        scanf("%d",&ans);
    }
    printf("\nPrinting the linked list\n");
    temp = start;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp = temp->next;
    }
    printf("\nEnter the target element to search :");
    scanf("%d",&target);
    printf("%d",b_search(&start,target));


}