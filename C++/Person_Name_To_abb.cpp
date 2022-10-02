#include<iostream>
using namespace std;
int main()
{
     char fname[20], mname[20], lname[20];
     cout<<"Enter The First Name Middle Name & Last Name \n";
     cin>>fname >>mname >>lname;
     cout<<"Abbreviated Name: ";
     cout<<fname[0]<<"."<<" "<<mname[0]<<"."<<" ";  cout<<lname<<endl;
     return 0;

}
