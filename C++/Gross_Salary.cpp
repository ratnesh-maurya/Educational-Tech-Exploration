#include<iostream>
using namespace std;
int main()
{

    float GrossPayment,basic,da,hra,da1,hra1;

    cout<<" Enter basic salary : ";
    cin>>basic;

   
    cout<<" Enter DA : ";
    cin>>da1;

    cout<<" Enter HRA : ";
    cin>>hra1;


    da = (da1 * basic) / 100;
    hra = (hra1 * basic) / 100;

    GrossPayment = basic + da + hra;

    cout<<"\n Gross Salary :"<<GrossPayment<<endl;;
    return (0);

}
