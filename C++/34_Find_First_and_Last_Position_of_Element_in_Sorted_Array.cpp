/*Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.*/

/*
->Make binary search functions to find starting and ending elements
->In the given function searchRange call the two binary search functions
*/
#include<bits/stdc++.h>
using namespace std;
int binaryFirst(vector<int>& arr, int target){
        int n = arr.size();
        int high = n-1, low = 0;
        while(low<=high){
            int mid = (high+low)/2;
                if((arr[mid]==target)&&(mid==0||arr[mid-1]!=arr[mid]))
                    return mid;
                else if((arr[mid]==target&&arr[mid-1]==arr[mid])||arr[mid]>target)
                    high = mid-1; 
                else
                    low = mid+1;
        }
        return -1;  
    }
    int binaryLast(vector<int>& arr, int target){
        int n = arr.size();
        int high = n-1, low = 0;
        while(low<=high){
            int mid = (high+low)/2;
                if((arr[mid]==target)&&(mid==n-1||arr[mid+1]!=arr[mid]))
                    return mid;
                else if((arr[mid]==target&&arr[mid+1]==arr[mid])||arr[mid]<target)
                    low = mid+1;               
                else
                    high = mid-1;
        }
        return -1;  
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {binaryFirst(nums,target),binaryLast(nums,target)};
    }
using namespace std;
 int main(void) { 
   
}