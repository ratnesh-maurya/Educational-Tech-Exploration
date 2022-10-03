// https://leetcode.com/problems/n-queens/
//N-queens problem Bactracking and recursive solution
//TC->N! SC->N


class Solution {
public:
    vector<vector<string>> ans;
    
    bool isSafe(int &r, int &c, int dp[][10], int &n)
    {
        // Col check
        for(int i=0; i<r; i++)
        {
            if(dp[i][c])
                return false;
        }
        
        // left diagonal
        for(int i=r, j=c; i>=0 and j>=0; i--, j--)
        {
            if(dp[i][j])
                return false;
        }
        
        // Right diagonal
        for(int i=r, j=c; i>=0 and j<n; i--, j++)
        {
            if(dp[i][j])
                return false;
        }
        
        return true;
    }
    
    void nQueen(int dp[][10], int r, int &n)
    {
        if(r == n)
        {
            vector<string>oneSoln; 
            string oneR;
            
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if(dp[i][j])
                        oneR += 'Q';
                    else
                        oneR += '.';
                }
                oneSoln.push_back(oneR);
                oneR = "";
            }
            
            ans.push_back(oneSoln);
            return;
        }
        
        
        for(int j=0; j<n; j++)
        {
            if(isSafe(r, j, dp, n))
            {
                dp[r][j] = 1;        
                nQueen(dp, r+1, n);
                dp[r][j] = 0;
            }
        }

    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        int dp[10][10] = {0};    
        
        nQueen(dp, 0, n);
        
        return ans;
        
    }
