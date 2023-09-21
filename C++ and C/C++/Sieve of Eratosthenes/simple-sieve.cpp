#include <bits/stdc++.h>
using namespace std;

void simpleSieve(int n){
    vector<bool> prime(n+1,true);
    prime[0] = prime[1] = false;

    for (int p=2; p*p<n; p++){
        if (prime[p] == true){
            for (int i=p*p; i<n; i+=p) prime[i] = false;
        }
    }
 
    for (int p=2; p<n; p++){
        if (prime[p] == true) cout<<p<< "  ";
    }
}

int main(){
    int n = 40;
    simpleSieve(n);
    return 0;
}