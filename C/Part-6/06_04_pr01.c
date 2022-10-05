#include<stdio.h>

int main(){
    int a=6;
    int *ptr;
    ptr = &a;
    printf("The value of variable a is %d\n", a);
    printf("The address of variable a is %u\n", ptr);
    printf("The value of variable a is %d\n", *ptr);
    return 0;
}