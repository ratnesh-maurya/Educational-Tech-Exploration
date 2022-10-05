#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int k =n;
for(int i =1;i<=n;i++){
    for(int j=1;j<=k;j++){
        cout<<"*";
       
    }
     k--;
    cout<<endl;
}

    return 0;
}
