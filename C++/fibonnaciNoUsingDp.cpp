#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define goog(tno) cout << "Case #" << tno <<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin >> x
using namespace std;



int dp[50];
int am_my11(int n){
    if(dp[n]!=-1)
        return dp[n];
    if(n<2)
        return n;
    else 
        return dp[n]= am_my11(n-1)+am_my11(n-2);
         
}
int fib(int n) {
    memset(dp, -1, sizeof(dp));
    int Ans = am_my11(n);
    return Ans;   
}
int main() {

    int n;
    cin >> n;
    
    cout << fib(n) << endl;
    return 0;
}

