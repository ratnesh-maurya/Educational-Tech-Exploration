#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    intstatus;
    char fileName[20];
    cout<<"Enter the Name of File: ";
    cin>>fileName;
    status = remove(fileName);
    if(status==0)
        cout<<"\nFile Deleted Successfully!";
    else
        cout<<"\nError Occurred!";
    cout<<endl;
    return 0;
}
