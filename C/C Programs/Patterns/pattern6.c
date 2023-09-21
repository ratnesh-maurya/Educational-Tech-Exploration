// 1 
// 2 2 
// 3 3 3 
// 4 4 4 4 
// 5 5 5 5 5


#include<stdio.h>
int main(){
    int n=5;
    int i,j;
    for ( i = 1; i <= n; i++)
    {
        for ( j = 1; j <= i; j++)
        {
            printf("%d ",i);
        }
        printf("\n");
    }
    
    return 0;
}