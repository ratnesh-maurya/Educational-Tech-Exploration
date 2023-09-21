//         * 
//       * * 
//     * * * 
//   * * * * 
// * * * * *

#include<stdio.h>
int main(){
    int n=5;
    int i,j;
    for ( i = 1; i <= n; i++)
    {
        for ( j = 1; j <= n-i; j++)
        {
            printf("  ");
        }
        for ( j ; j <= n; j++)
        {
            printf("* ");
        }
        
        printf("\n");
    }
    
    return 0;
}