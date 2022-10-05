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
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            if(j<(n-i)){
                cout<<j+1<<" ";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
