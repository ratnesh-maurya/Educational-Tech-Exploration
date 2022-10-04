#include <iostream>
using namespace std;

int binaryS(int a[], int target, int s, int e)
{

    if (s > e)
    {
        return -1;
    }

    int m = s + (e - s) / 2;

    if (a[m] == target)
    {
        return m;
    }
    if (target > a[m])
    {
        return binaryS(a, target, s = m + 1, e);
    }
    return binaryS(a, target, s = 0, e = m - 1);
}

int main()
{

    int a[5] = {1, 2, 3, 4, 5};

    cout << binaryS(a, 4, 0, 4);

    return 0;
}