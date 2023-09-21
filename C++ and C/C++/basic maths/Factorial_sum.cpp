
// Author: ADARSH
/*  Write a program to compute, sum= 1! +2! +3! +4! ... n!. */

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    cout << "\nEnter a number: ";
    int num, sum=0;
    cin >> num;

    for (int j = 1; j <= num; j++)
    {
        int fact = 1;
        for (int i = 2; i <= j; i++)
        {
            fact *= i;
        }
        sum += fact;
    }

    cout << sum << endl;

    return 0;
}
