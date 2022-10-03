#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    // input number of elements in array
    cin>>n;
    int a[n];
    
    // input array
    for(int i=0;i<n;i++) cin>>a[i];
    
    vector<int> v;
    v.push_back(a[0]);
    for(int i=1;i<n;i++) {
        if(v[v.size()-1] < a[i]) v.push_back(a[i]);
        else {
            int x = lower_bound(v.begin(),v.end(),a[i])-v.begin();
            v[x]=a[i];
        }
    }
  
    cout<<v.size();
    return 0;
}
