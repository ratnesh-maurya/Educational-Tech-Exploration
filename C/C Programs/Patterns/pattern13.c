//         A 
//       A B A 
//     A B C B A 
//   A B C D C B A 
// A B C D E D C B A

#include<stdio.h>
int main()
{
    int n=5;
    int i,j;
    for ( i = 1; i <= n; i++)
    {
        int a=65;
        for ( j = 1; j <= n-i; j++)
        {
            printf("  ");
        }
        for ( j ; j <= n; j++)
        {
            printf("%c ",(char)a);
            a+=1;
        }
        a-=2;
        for ( j ; j <= n+i-1; j++)
        {
            printf("%c ",(char)a);
            a-=1;
        }
        printf("\n");   
    }
    return 0;
}