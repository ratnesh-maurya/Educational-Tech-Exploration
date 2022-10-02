
// Author: ADARSH
/* Write a program that converts an amount (in integer, upto 999999) into words.[i/p –231504, output –2 lakh 31 thousand 5 hundred and four only] */

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int amt, c=0;
    cout << "Enter an amount:";
    cin >> amt;
    if(amt < 0)
    {
        printf("-");
        amt *= -1;
    }

    if (amt/100000>0)
    {
        printf("%d lakh ", amt/100000);
        amt %= 100000;
    }
    if(amt/1000>0)
    {
        printf("%d thousand ", amt/1000);
        amt %= 1000;
    }
    if (amt/100>0)
    {
        printf("%d hundred ",amt/100);
        amt %= 100;
    }

    switch(amt/10)
    {
        case 1:
        switch (amt%10)
        {
            case 1: printf("and eleven only.\n\n");
            break;
            case 2: printf("and twelve only.\n\n");
            break;
            case 3: printf("and thirteen only.\n\n");
            break;
            case 4: printf("and fourteen only.\n\n");
            break;
            case 5: printf("and fifteen only.\n\n");
            break;
            case 6: printf("and sixteen only.\n\n");
            break;
            case 7: printf("and seventeen only.\n\n");
            break;
            case 8: printf("and eighteen only.\n\n");
            break;
            case 9: printf("and nineteen only.\n\n");
            break;
        }
        break;
        case 2: printf("and twenty ");
        break;
        case 3: printf("and thirty ");
        break;
        case 4: printf("and fourty ");
        break;
        case 5: printf("and fifty ");
        break;
        case 6: printf("and sixty ");
        break;
        case 7: printf("and seventy ");
        break;
        case 8: printf("and eighty ");
        break;
        case 9: printf("and ninety ");
        break;
        case 0: c++;
    }

    printf((amt%10!=0 && c!=0)?"and ":"");

    switch (amt%10)
    {
        case 1: printf("one only.\n\n");
        break;
        case 2: printf("two only.\n\n");
        break;
        case 3: printf("three only.\n\n");
        break;
        case 4: printf("four only.\n\n");
        break;
        case 5: printf("five only.\n\n");
        break;
        case 6: printf("six only.\n\n");
        break;
        case 7: printf("seven only.\n\n");
        break;
        case 8: printf("eight only.\n\n");
        break;
        case 9: printf("nine only.\n\n");
        break;
        case 0: printf("only.\n\n");
        break;
    }

    return 0;

}
