#include<stdio.h>

int main(){
    int a; //lower limit
    int b; //upper limit
    int j; 
    int i;
    printf("Enter lower limit :\n");
    scanf("%d",&a);
    printf("Enter upper limit :\n");
    scanf("%d",&b);
    printf("The prime numbers between %d and %d are :\n",a,b);
    for ( i=a ; i <= b; i++) //a<= i <= b
    {
        if (i==1 || i==0) 
        {
            continue;
        }
        int ans=1;
        for(j=2; j<i ; j++)
        {
            if (i%j==0)
            {
                ans=0;
                break;
            }
            
        }
        if (ans==1){
            printf("%d\n",i);
        }
    }
    return 0;
}