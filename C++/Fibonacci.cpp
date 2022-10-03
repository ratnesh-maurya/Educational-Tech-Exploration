#include<iostream>
using namespace std;
int main (){
    int n, term1 =0, term2 =1, nextTerm =0;

    cout <<"Enter the number of terms: ";
    cin >> n;
    cout << "Fibonacci series: ";

    for (int i = 1; i<= n; ++i){ 
        if (i== 1){
            cout << term1 << ", ";
            continue;
        }
        if (i==2){
            cout << term2 << ", ";
            continue;
        }
       nextTerm = term1 + term2;
       term1 = term2;
       term2 = nextTerm;

       cout << nextTerm << ", ";
    }

return 0;
}