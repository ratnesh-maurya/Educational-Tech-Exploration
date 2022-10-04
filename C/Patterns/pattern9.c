//         1 
//       1 0 
//     1 0 1 
//   1 0 1 0 
// 1 0 1 0 1

#include<stdio.h>
int main(){
    int n=5;
    int i,j;
    for ( i = 1; i <= n; i++){
        for (j = 1; j <= n-i; j++)
        {
            printf("  ");
        }
        for (j ; j <= n; j++)
        {
            if ((i+j)%2==0)
            {
                printf("1 ");
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
        
    }
    return 0;
}