/*
The Fibonacci numbers are the numbers in the following integer sequence.
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ……..

In mathematical terms, the sequence Fn of Fibonacci numbers is defined by the recurrence relation

Fn = Fn-1 + Fn-2
with seed values 

F0 = 0 and F1 = 1.
*/
#include<iostream>
using namespace std;

int fin(int i)
{
  //base case
  if(i==0 || i==1)
  return i;

  //recursive call
  else return fin(i-1)+fin(i-2);

}

int main()
{
    int n;
    cout<<"Enter the term:"<<endl;
    cin>>n;
    cout<<"The "<<n<<"  term of finabonacci series is ";
    cout<<fin(n);
    
}