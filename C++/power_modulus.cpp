#include<bits/stdc++.h>

using namespace std;
const int mod =1e9+7;
int power(int a,int b)
{
   int ans=1;
   while(b)
   {
      if(b&1)
      {
         ans = (a*1LL*ans)%mod;
      }
      a=(a*1LL*a)%mod;
      b>>=1;
   }
   return ans;
}

int main()
{
    int a,b;
    cin >> a >> b;
    cout<<power(a,b)<<endl;
}