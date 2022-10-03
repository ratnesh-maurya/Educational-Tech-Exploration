// Leetcode 1752 :: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

bool check(vector<int> &nums)
{

    int c = 0;
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] > nums[i + 1] and c == 0)
            c = 1;
        else if (nums[i] > nums[i + 1] and c == 1)
            c = -1;
    }
    if (nums[n - 1] > nums[0] and c == 1)
        return false;

    if (c == 0 or c == 1)
        return true;
    else
        return false;
}