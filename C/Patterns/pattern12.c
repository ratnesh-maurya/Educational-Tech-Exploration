// * * * * * * * * * 
//   * * * * * * * 
//     * * * * * 
//       * * * 
//         *

#include<stdio.h>
int main()
{
    int n=5;
    int i,j;
    int a=65;
    for ( i = 1; i <= n; i++)
    {
        for (j = 1; j < i; j++)
        {
            printf("  ");
        }
        for ( j ; j <= n; j++)
        {
            printf("* ");
        }
        for ( j ; j <= n+n-i; j++)
        {
            printf("* ");
        }
        printf("\n");
        
    }
    return 0;
}