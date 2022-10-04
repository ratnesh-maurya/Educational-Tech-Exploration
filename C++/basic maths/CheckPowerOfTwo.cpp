#include<bits/stdc++.h>
using namespace std;

// If the number is a power of two or not

bool isPower(int n)
{
   if (n == 1) return 1;

   if (n % 2 != 0 || n == 0) return 0;
   return isPower(n/2);
}
int main()
{
   int a;
   cin>>a;
   isPower(a) ? cout<<"True" : cout<<"False";
}