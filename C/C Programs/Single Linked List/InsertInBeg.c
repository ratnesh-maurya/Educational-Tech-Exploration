#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};
typedef struct node Node;

void new_ele_beg(Node** st, int ele)
{
    Node* temp;
    temp = (Node*)malloc(sizeof(Node));
    temp->data = ele;
    temp->next = *st;
    *st = temp; 

}

int main()
{
    Node* start;
    Node* temp;
    int ans;
    int newEle;
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

    printf("\nEnter the element to add in beginnig :");
    scanf("%d",&newEle);

    new_ele_beg(&start,newEle);
    printf("\nPrinting the linked list after insertion\n");
    temp = start;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp = temp->next;
    }

}