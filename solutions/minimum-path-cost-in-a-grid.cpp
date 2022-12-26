// https://leetcode.com/problems/minimum-path-cost-in-a-grid

class Solution {
public:
    int minPathCost(vector<vector<int>>& g, vector<vector<int>>& moveCost) {
        int m = g.size(), n = g[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[0] = g[0];
        for (int i = 1; i < m; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < n; ++k)
                    dp[i][k] = min(dp[i][k], g[i][k] + dp[i - 1][j] + moveCost[g[i - 1][j]][k]);
        return *min_element(begin(dp[m - 1]), end(dp[m - 1]));
    }
};