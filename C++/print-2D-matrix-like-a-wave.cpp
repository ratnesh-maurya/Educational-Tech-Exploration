/*This is one of the most asked questions in interviews on 2-D arrays

For your practice here is the link
Problem link = https://www.codingninjas.com/codestudio/problems/print-like-a-wave_893268

Time Complexity = O(n*m)

*/

#include <bits/stdc++.h> 
using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    //create a vector to store our ans
    vector<int> ans;
    
    //the logic is for odd columns we need to traverse bottom to top and vice versa
    //traversing column wise
    for(int col = 0 ; col < mCols ; col++){
        if(col & 1){
            //odd case -> bottom to top
            for(int row = nRows - 1 ; row>=0 ;  row--){
                ans.push_back(arr[row][col]);
            }
        }
        else{
            //even case -> top to bottom
            for(int row = 0 ; row<nRows ; row++){
                ans.push_back(arr[row][col]);
            }
        }
    }
    return ans;
}