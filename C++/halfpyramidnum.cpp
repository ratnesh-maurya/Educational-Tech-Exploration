#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int k =n;
for(int i =1;i<=n;i++){
    for(int j=1;j<=n;j++){
        if(j<=i){
            cout<<i;
        }
        else{
            cout<<" ";
        }
       
    }
   //  k--;
    cout<<endl;
}

    return 0;
}
