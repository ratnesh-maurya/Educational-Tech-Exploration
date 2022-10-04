#include <bits/stdc++.h>
using namespace std;

// Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:
// [4,5,6,7,0,1,2] if it was rotated 4 times.
// [0,1,2,4,5,6,7] if it was rotated 7 times.
// Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
// Given the sorted rotated array nums of unique elements, return the minimum element of this array.

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        if (nums[nums.size() - 1] > nums[0])
            return nums[0];

        int l = 0, r = nums.size() - 1, mid;
        while (l < r)
        {
            mid = (l + r) / 2;
            if (mid > 0 && nums[mid] < nums[mid - 1])
                return nums[mid];
            if (mid < nums.size() - 1 && nums[mid + 1] < nums[mid])
                return nums[mid + 1];

            if (nums[mid] > nums[0])
                l = mid + 1;
            else
                r = mid - 1;
        }

        return nums[l];
    }
};