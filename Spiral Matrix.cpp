#include<iostream>
#include <bits/stdc++.h>
#include<vector>
using namespace std;
void spiral(vector<vector<int>>v){
    int l=0,k=0;
    int i=0;
    int r=v.size()-1;
    int c=v[i].size()-1;
   // cout<<"mansi";
   // vector<int>ans;
    while (k<=r && l<=c)
    {
    
    
    for(i=l;i<=c;i++){
        cout<<v[k][i]<<" ";
    } k++;
    for(i=k;i<=r;i++){
        cout<<v[i][c]<<" ";
    }c--;
    
    for(i=c;i>=l;i--){
        cout<<v[r][i]<<" ";
    }r--;
    

    for(i=r;i>=k;i--){
        cout<<v[i][l]<<" ";
    }l++;
    
    }
   // return ans;
}
void display(vector<vector<int>>v){
    int i,j;
    for(i=0;i<v.size();i++){
        for(j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

}
int main(){
    vector<vector<int>>v={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    display(v);
     spiral(v);
     
}
