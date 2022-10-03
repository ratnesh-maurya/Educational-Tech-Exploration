/*53. Maximum Subarray
Solution Runtime - 0ms
Memory - 13.1 MB

Given an integer array nums, find the contiguous subarray 
(containing at least one number) which has the largest sum and return its sum.
A subarray is a contiguous part of an array.*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
          int n = nums.size();
    if(n == 0){
        return 0;
    }
    
    int ans = INT_MIN;
    int sum = 0;
    
    for(int i=0; i<n; i++){

        sum += nums[i];
        
        ans = max(ans, sum);
		
       if(sum < 0){
            sum = 0;
        }
    }
    
    return ans;
   }
};