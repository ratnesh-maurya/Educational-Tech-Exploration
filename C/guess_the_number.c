#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
int a, guess,nguesses=1;
srand(time(0));
a=rand()%100+1;
    // printf("the random no is %d\n",a);
    do
    {
 printf("please guess the number between 1 to hunderd\n");
 scanf("%d",&guess);
 if (guess>a)
 {
     printf("lower number please!|n");
 }
 else if (guess<a)
 {
     printf("higher number please\n");

 }
 else printf("you guess the number in %d attempts /n",nguesses);
nguesses++;
 }
 
 while (guess!=a);
  return 0;
 
    }
   