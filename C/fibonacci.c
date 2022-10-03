//using recursion
#include<stdio.h>

void fibonacci(int a,int b,int n)
{
    
    if (n>0)
    {
        printf("%d ",a);
        int c=a+b;
        a=b;
        b=c;
        --n;
        fibonacci(a,b,n);
    }

}

int main()
{
    int n1,n2,N;
    printf("Enter the first number :");
    scanf("%d",&n1);
    printf("Enter the second number :");
    scanf("%d",&n2);
    printf("Enter the number terms :");
    scanf("%d",&N);
    fibonacci(n1,n2,N);
    
    
    return 0;
}