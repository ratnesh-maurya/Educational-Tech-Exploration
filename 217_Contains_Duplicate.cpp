/*    Contains Duplicates

      Leetcode 217 :: https://leetcode.com/problems/contains-duplicate/
*/

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> set;
        for (int i : nums)
        {
            set.insert(i);
        }
        return !(set.size() == nums.size());
    }
};