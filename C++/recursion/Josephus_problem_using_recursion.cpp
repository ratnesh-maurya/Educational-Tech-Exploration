#include <bits/stdc++.h>
using namespace std;
 

int joss(int n, int k)
{
    if (n == 1)
        return 1;
    else
        return (joss(n - 1, k) + k - 1) % n + 1;
}
 
int main()
{
    int n = 14;
    int k = 2;
    cout << "The chosen place is " << joss(n, k);
    return 0;
}
/*OUTPUT:
The chosen place is 13*/
