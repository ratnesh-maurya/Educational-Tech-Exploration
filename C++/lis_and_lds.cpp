#include <bits/stdc++.h>

using namespace std;

// Longest Decreasing Susequence
int LDS(int *a,int n) {
    int dp[100000];
    dp[n-1] = 1;
    for(int i=n-2;i>=0;i--) {
        int j = i+1;
        dp[i] = 1;
        while(j<n) {
           if(a[j]<=a[i]){
                dp[i] = max(dp[i],dp[j]+1);
            }
            j++;
        }
    }

    int ans = INT_MIN;
    for(int i=0;i<n;i++) {
        // cout << dp[i] << " ";
        ans = max(ans, dp[i]);
    }
    return ans;
}

// Longest Increasing Susequence
int LIS(int *a, int n) {
//    dp[i] denotes the lenght of longest increasing subsequence ending at ith index
    int dp[100000];
    dp[0] = 1;
    for(int i=1;i<n;i++) {
        int j = i-1;
        dp[i] = 1;
        while(j>=0) {
            if(a[j]<=a[i]){
                dp[i] = max(dp[i],dp[j]+1);
            }
            j--;
        }
    }
    int ans = INT_MIN;
    for(int i=0;i<n;i++) {
        // cout << dp[i] << " ";
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    // longest increasing subsequence
    cout << LIS(a,n) << endl;
    // longest decreasing subsequence
    cout << LDS(a,n) << endl;
    return 0;
}
