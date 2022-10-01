//  Kadane's Algorithm
// It is used to findout Maximum sum contiguous subarray within a one-dimensional array of numbers .
//Kadane's Algorithm is an iterative dynamic programming algorithm.


/*
Initilize...
        maxSum = INT_MIN
        currentSum = 0

    Loop for each element of Array.

        a. currentSum = currentSum + a[i]

        b. if (currentSum < 0)
            currentSum = 0 
        
        c.  if(maxSum < currentSum)
            maxSum = currentSum
    

    return maxSum
*/


/*
    Time Complexcity = O(N)
    Auxiliary Space = O(1)
*/



#include<iostream>
#include<climits>
#include<vector>
using namespace std;

  

int main()
{
     int n;
    cout<<"Array size"<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter array's elements"<<endl;
    for(int i=0; i<n; ++i){
        cin>>arr[i];
    }

    int currsum = 0;
    int maxsum = INT_MIN;

    for(auto i : arr){
        currsum += i;
        if(currsum < 0 ){
            currsum = 0;
        }

        maxsum = max(maxsum, currsum);
    }

    cout<<maxsum<<endl;
    return 0;
}