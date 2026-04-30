class Solution {
public:
    int rec(int i, int j, int rem, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
        if(i >= grid.size() or j >= grid[0].size() or rem < 0) return INT_MIN;
        if(i == grid.size() - 1 and j == grid[0].size() - 1) {
            if(rem > 0) return grid[i][j]; 
            if(rem == 0 and grid[i][j] == 0) return grid[i][j];
            return INT_MIN;
        }
        int &ans = dp[i][j][rem];
        if(ans != INT_MIN) return ans;
        int cost = grid[i][j] != 0;
        // go down
        ans = max(ans, grid[i][j] + rec(i, j+1, rem-cost, grid, dp));
        // go right
        ans = max(ans, grid[i][j] + rec(i+1, j, rem-cost, grid, dp));
        return ans;
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int> (k+1, INT_MIN)));
        int ans = rec(0, 0, k, grid, dp);
        if(ans < 0) return -1;
        return ans;
    }
};
