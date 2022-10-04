#include<iostream> 
using namespace std; 

  int main(){
    int i,a,b;
cin>>a>>b;

string nums[11] = {"one","two","three","four","five","six","seven","eight","nine","even","odd"};

for (i=a; i<=b; i++){
    if (i>9 && i%2==0)
    {
        cout<<nums[9]<<endl;
    }
    else if (i>9 && i%2!=0)
    {
            cout<<nums[10]<<endl;
    }
    else{
        cout<<nums[i-1]<<endl;
    }
}

     return 0;
}