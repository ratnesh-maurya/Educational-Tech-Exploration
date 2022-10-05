#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double

int main(){

ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j =1;j<=(n-i);j++){
            cout<<" ";
        }
        for(int k=i;k>=1;k--){
            cout<<k;
        }
        if(i>=2){
            for(int k=2;k<=i;k++){
            cout<<k;
        }

        }
        
        cout<<endl;
    }
    return 0;
}
