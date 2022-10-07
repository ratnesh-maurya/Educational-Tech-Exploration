#include<stdio.h>

int main(){
    int n=4;
    int row,k;
    for (row = 1; row <= n; row++)
    {
        int col;
        for (col = 1; col <= n-row; col++)
        {
            printf(" ");
        }
        int a=65;
        for (col; col <= n; col++)
        {
            printf("%c",(char)a);
            a+=1;
        }
        a-=2;
        for (col ; col <= n+row-1; col++)
        {
            printf("%c",(char)a);
            a-=1;
        }
        printf("\n");    
        
    }
    
    return 0;
}