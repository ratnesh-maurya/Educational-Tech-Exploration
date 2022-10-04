#include<iostream>
using namespace std;


int main() {
    
    int n,i=1;
    cin>>n;
    
    while(i<=(n+1)/2){
        int k=1;
        while(k<=(n+1)/2-i){
            cout<<" ";
            k++;
        }
        int j=1;
        while(j<=2*i-1){
            cout<<"*";
            j++;
        }
        cout<<endl;
        i++;
    }
    int max=n-(n+1)/2;
    int var=max;
    int x=1;
    while(x<=max){
        int z=1;
        while(z<=x){
            cout<<" ";
            z++;
        }
        int ran=1;
        while (ran<=2*var-1){
            cout<<"*";
            ran++;
        }
        var--;
        cout<<endl;
        x++;
    }
    
    
    
}

