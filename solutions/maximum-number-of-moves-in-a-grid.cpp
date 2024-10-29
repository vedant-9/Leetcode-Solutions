class Solution {
public:
    int rec(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &dp) {
        if(i >= grid.size() or j >= grid[0].size() or i < 0) return 0;
        
        int ans = dp[i][j];
        if(ans != -1) return ans;
        
        ans = 0;
        
        if(i-1 >= 0 and j+1 < grid[0].size() and grid[i][j] < grid[i-1][j+1])
            ans = max(ans, rec(i-1, j+1, grid, dp) + 1);
        
        if(j+1 < grid[0].size() and grid[i][j] < grid[i][j+1]) 
            ans = max(ans, rec(i, j+1, grid, dp) + 1);
        
        if(i+1 < grid.size() and j+1 < grid[0].size() and grid[i][j] < grid[i+1][j+1])
            ans = max(ans, rec(i+1, j+1, grid, dp) + 1);
        
        return dp[i][j] = ans;
    }   
    int maxMoves(vector<vector<int>>& grid) {
        int res = 0;
        vector<vector<int>> dp(grid.size(), vector<int> (grid[0].size(), -1));
        for(int i = 0; i < grid.size(); i++) {
            res = max(res, rec(i, 0, grid, dp));
        }
        return res;
    }
};
