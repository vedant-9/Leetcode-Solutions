// https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k

class Solution {
public:
    const int mod = 1e9+7;
    int rec(int i, int j, int sum, vector<vector<int>> &grid, int k, vector<vector<vector<int>>> &dp) {
        int m = grid.size(), n = grid[0].size();
        if(i<0 or j<0 or i>=m or j>=n) return 0;
        sum = (sum + grid[i][j])%k;
        if(i==m-1 and j==n-1) return (sum%k==0);
        
        int &ans = dp[i][j][sum];
        if(ans != -1) return ans;
        
        // move right
        ans = rec(i, j+1, sum, grid, k, dp);
        
        // move down
        ans = (ans + rec(i+1, j, sum, grid, k, dp))%mod;
        
        return ans;
    }
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(k+1, -1)));
        return rec(0, 0, 0, grid, k, dp);
    }
};