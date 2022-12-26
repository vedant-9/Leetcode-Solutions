// https://leetcode.com/problems/cherry-pickup

class Solution {
public:
    // simultaneous dfs of two persons from (0,0) to (n-1,n-1)
    int dp[51][51][51];
    int dfs(vector<vector<int>>& grid, int r1, int c1, int r2) {
        int n = grid.size();
        
        // r1+c1 = r2+c2
        int c2 = r1+c1-r2;
        
        if(r1>=n or r2>=n or c1>=n or c2>=n or grid[r1][c1] == -1 or grid[r2][c2] == -1) 
            return INT_MIN;
        
        if(r1 == n-1 and c1 == n-1)
            return grid[r1][c1];
        
        if(dp[r1][c1][r2] != -1)
            return dp[r1][c1][r2];
        
        int totalCherry = 0;
        
        // both are at same cell
        if(r1==r2 and c1==c2) 
            totalCherry += grid[r1][c1];
        else 
            totalCherry += grid[r1][c1]+grid[r2][c2];
        
        int downDown   = dfs(grid, r1+1, c1, r2+1);
        int downRight  = dfs(grid, r1+1, c1, r2);
        int rightDown  = dfs(grid, r1, c1+1, r2+1);
        int rightRight = dfs(grid, r1, c1+1, r2);

        totalCherry += max({downDown, downRight, rightDown, rightRight});
        
        return dp[r1][c1][r2] = totalCherry;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                for(int k=0;k<n;k++)
                    dp[i][j][k] = -1;
            }
        }
        int ans = dfs(grid, 0, 0, 0);    
        if(ans<0)
            ans = 0;
        return ans;
    }
};