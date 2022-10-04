#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll primefactors(ll n, vector<ll> p)
{
    ll count = 0;
    int sum = 0;
    while (n % 2 == 0)
    {
        sum += 2;
        p.push_back(2);
        n = n / 2;
        count++;
    }
    for (ll i = 3; i * i <= n; i = i + 2)
    {
        count = 0;
        while (n % i == 0)
        {
            // sum+= i;
            p.push_back(i);
            n = n / i;
			// COUNT NO OF TIMES THAT PRIME OCCURS AS FACTOR
            count++;
        }
        int temp = i;
        int digit_sum = 0; 

		// SUM OF DIGITS HERE AS WELL 
        while (temp)
        {
            digit_sum += (temp % 10);
            temp /= 10;
        }
		// DIGITSUM * COUNT OF TIME IT OCCURED AS FACTOR
        sum += (digit_sum * count);
    }
    if (n > 3)
    {
        
        int temp = n;
        int digit_sum = 0;
        while (temp)
        {
            digit_sum += (temp % 10);
            temp /= 10;
        }
        sum += digit_sum;
    }
    return sum;
}
int main()
{
    ll n;
    cin >> n;
    vector<ll> p;

    ll sum = primefactors(n, p);

    ll digitsum = 0;
    while (n > 0)
    {
        ll digit = n % 10;
        digitsum += digit;
        n = n / 10;
    }
    // cout << digitsum<< "  ";
    if (digitsum == sum)
    {
        cout << "1" << endl;
    }
    else
        cout << "0" << endl;
}
