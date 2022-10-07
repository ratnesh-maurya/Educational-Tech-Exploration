#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int getrandom(int a)
{

    srand(time(NULL));

    return (rand() % a);
}

int main()
{
    int a=3;
    int b, c;
    int d = 0;
    int e = 0;

    char arr[20];

    printf("enter your name :\n");
    scanf("%s",&arr);
    b = getrandom(a);
    for (int i = 0; i < 3; i++)
    {

        printf("press 0 for rock \npress 1 for paper \npress 2 for scissors \n");
        scanf("%d",&c);
        if (b == c)
        {

            printf("its a tie between %s and master \n", arr);
        }
        else if ((c == 0) &&(b == 1))
        {

            printf("master defeat %s\n", arr);

            e+=1;
        }
        else if ((c == 1) && (b == 2))
        {

            printf("master defeat %s\n", arr);

            e+=1;
        }
        else if ((c == 2) && (b == 0))
        {

            printf("master defeat %s\n", arr);

            e+=1;
        }
        else if ((b == 0) && (c == 1))
        {

            printf("%s defeat master\n", arr);

            d+=1;
        }
        else if ((b == 1) && (c == 2))
        {

            printf("%s defeat master\n", arr);

            d+=1;
        }
        else if ((b==2) && (c==0))
        {

            printf("%s defeat master\n", arr);

            d+=1;
        }
    }

    printf("the score of %s is %d \n", arr, d);
    printf("the score of master is %d \n", e);

    if (d > e)
    {

        printf("master is the winner\n");
    }
    else if (e > d)
    {

        printf("%s is the winner\n", arr);
    }

    return 0;
}