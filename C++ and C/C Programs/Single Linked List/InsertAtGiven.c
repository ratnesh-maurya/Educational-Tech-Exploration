#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};
typedef struct node Node;

void print_ll(Node** st)
{
    printf("\nPrinting the linked list after insertion\n");
    Node* temp;
    temp = *st;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp = temp->next;
    }
}

void new_ele(Node** st, int ele, int target)
{
    Node* new;
    Node* temp;
    temp = *st;
    int found = 0;
    new = (Node*)malloc(sizeof(Node));
    new->data = ele;
    while(temp->next!=NULL)
    {
        if (temp->data == target)
        {
            found = 1;
            new->next = temp->next;
            temp->next = new;
            break;
        }
        temp = temp->next;
    }
    if (found==0)
    {
        temp->next = new;
        new->next = NULL;
    }
    
}

int main()
{
    Node* start;
    Node* temp;
    int ans;
    int newEle;
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
    print_ll(&start);

    printf("\nEnter the element to add :");
    scanf("%d",&newEle);
    printf("\nEnter the element after which you want to enter :");
    scanf("%d",&target);

    new_ele(&start,newEle,target);
    print_ll(&start);

}