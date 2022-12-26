// https://leetcode.com/problems/01-matrix

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int m = mat.size(), n = mat[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n));
        int mx = m*n;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    // up and left are precalculated
                    int up = (i>0)?dp[i-1][j]:mx;
                    int left = (j>0)?dp[i][j-1]:mx;
                    dp[i][j] = min(up,left)+1;
                }
            }
        }
        
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(mat[i][j]==0)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    // down and right are precalculated
                    int down = (i<m-1)?dp[i+1][j]:mx;
                    int right = (j<n-1)?dp[i][j+1]:mx;
                    dp[i][j] = min(dp[i][j],min(down,right)+1);
                }
            }
        }
        
        return dp;
    }
};