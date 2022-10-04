#include <bits/stdc++.h>
using namespace std;

// Problem Link: https://leetcode.com/problems/search-a-2d-matrix/

// Problem Statement:
// Write an algorithm to search for a value target in an m x n integer matrix matrix. This matrix has the following properties:
// 1. Integers in each row are sorted from left to right.
// 2. The first integer of each row is greater than the last integer of the previous row.

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();
        int r = 0, c = n - 1;

        while (r < m && c >= 0)
        {
            if (matrix[r][c] == target)
                return true;
            if (matrix[r][c] < target)
                r++;
            else
                c--;
        }

        return false;
    }
};