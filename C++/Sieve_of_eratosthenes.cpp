#include<bits/stdc++.h>
using namespace std;


// complexity O(log(log N))
int count_prime(int n)
{
    int count = 0;
    vector<bool> prime(n+1,true);


    // 0 and 1 are non prime
    prime[0] = false;

    if(n>0)
    {
        prime[1] = false;
    }

    for (int i = 2; i < n; i++)
    {
        if(prime[i])
        {
            count++;

            int j = i+i;

            while(j<n)
            {
                prime[j] = false;
                j+=i;
            }
        }

    }

    return count;
}



int main()
{
    cout<<count_prime(100);
    return 0;
}