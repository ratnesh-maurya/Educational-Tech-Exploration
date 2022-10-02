// C++ program to find subarray having maximum sum less than or equal to sum
// Time Complexity: O(N*log(N))
// Auxiliary Space: O(1)


#include <bits/stdc++.h>
using namespace std;
 
// To find subarray with maximum sum
// less than or equal to sum
int findMaxSubarraySum(int arr[], int n, int sum)
{
    // To store current sum and
    // max sum of subarrays
    int curr_sum = arr[0], max_sum = 0, start = 0;
 
    // To find max_sum less than sum
    for (int i = 1; i < n; i++) {
 
        // Update max_sum if it becomes
        // greater than curr_sum
        if (curr_sum <= sum)
            max_sum = max(max_sum, curr_sum);
 
        // If curr_sum becomes greater than
        // sum subtract starting elements of array
        while (start < i && curr_sum + arr[i] > sum) {
            curr_sum -= arr[start];
            start++;
        }
 
        // If cur_sum becomes negative then start new subarray
        if (curr_sum < 0)
        {
            curr_sum = 0;
        }
 
        // Add elements to curr_sum
        curr_sum += arr[i];
 
    }
 
    // Adding an extra check for last subarray
    if (curr_sum <= sum)
        max_sum = max(max_sum, curr_sum);
 
    return max_sum;
}
 
// Driver program to test above function
int main()
{
    int arr[] = {6, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 20;
 
    cout << findMaxSubarraySum(arr, n, sum);
 
    return 0;
}