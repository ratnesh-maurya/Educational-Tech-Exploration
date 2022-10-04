#include <bits/stdc++.h>
struct Node {
    int data;
    struct Node* next;
};

void display(struct Node* ptr){
    while(ptr!=0){
        printf("%d " ,ptr->data);
        ptr= ptr->next;
    }
    printf("\n");
}

struct Node* insert_at_beginning(struct Node* start, int data1){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data1;
    ptr->next = start;
    start = ptr;
    return start;
}

struct Node* insert_in_between(struct Node* start, int data, int index){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = start;
    int i=0;
    while(i!=index-1){
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    p = start;
    return p;
}

struct Node* insert_at_the_end(struct Node* start, int data){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node)), *p;
    ptr->data = data;
    p = start;
    while(p->next!=NULL){
        p = p->next; 
    }
    p->next = ptr;
    ptr->next = NULL;
    return start;
}

struct Node* delete_at_beginning(struct Node* start){
    struct Node* p;
    p = start;
    start = start->next;
    free(p);
    return start;
}

struct Node* delete_in_between(struct Node* start, int index){
    struct Node* p=start, *q=start->next;
    int i=0;
    while(i!=index-1){
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    free(q);
    return start;
}
struct Node* delete_at_the_end(struct Node* start){
    struct Node* p = start,*q = start->next;
    while(q->next != NULL){
        q = q->next;
        p = p->next;
    }
    p->next = NULL;
    free(q);
    return start;
}

struct Node * delete_at_given_key(struct Node* start, int key){
    struct Node* ptr = start,*q=start->next;
    while(q->data!=key && q->next!=NULL){
        ptr=ptr->next;
        q = q->next;
    }
    ptr->next = q->next;
    free(q);
    return start;
}


int main()
{
    struct Node *start,*second,*third;
    start = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    start->data=5;
    start->next=second;
    second->data=6;
    second->next=third;
    third->data=2;
    third->next= NULL;
    display(start);
    start = insert_at_beginning(start,4);
    display(start);
    start = insert_in_between(start,22,2);
    display(start);
    start = insert_at_the_end(start,2);
    display(start);
    start = delete_at_beginning(start);
    display(start);
    start = delete_in_between(start,2);
    display(start);
    start = delete_at_the_end(start);
    display(start);
    start = delete_at_given_key(start,22);
    display(start);
return 0;
}