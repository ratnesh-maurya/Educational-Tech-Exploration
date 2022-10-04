
// Author: ADARSH
// https://github.com/ADARSH-863

/*   Write a recursive function to findout factorial of a given integer.   */

#include <bits/stdc++.h>
using namespace std;

int recurFact(int n) {
    return (n == 0) ? 1 : n * recurFact(n-1);
}

int main(int argc, char const *argv[])
{
    int x;
    cout << "\nEnter a number: ";
    cin >> x;
    cout << "The factorial of " << x << " = " << recurFact(x);

    return 0;
}
