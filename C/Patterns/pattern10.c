// A B C D E 
//   A B C D 
//     A B C 
//       A B 
//         A

#include<stdio.h>
int main(){
    int n=5;
    int i,j;
    for ( i = 1; i <= n; i++)
    {
        int a=65;
        for (j = 1; j<i ; j++)
        {
            printf("  ");
        }
        for ( j ; j <= n; j++)
        {
            printf("%c ",(char)a);
            a+=1;
        }
        printf("\n");
        
    }
    
    return 0;
}