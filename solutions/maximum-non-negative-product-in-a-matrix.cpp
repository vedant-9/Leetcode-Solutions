class Solution {
public:
    const int MOD = 1e9 + 7;
    const long long UNSET = LLONG_MIN;

    long long dp[15][15][2];

    pair<long long, long long> rec(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        long long cur = grid[i][j];

        if (i == m - 1 && j == n - 1)
            return {cur, cur};

        if (dp[i][j][0] != UNSET)
            return {dp[i][j][0], dp[i][j][1]};

        long long mx = LLONG_MIN, mn = LLONG_MAX;

        if (j + 1 < n) {
            auto [rMx, rMn] = rec(grid, i, j + 1);
            mx = max(mx, max(cur * rMx, cur * rMn));
            mn = min(mn, min(cur * rMx, cur * rMn));
        }

        if (i + 1 < m) {
            auto [dMx, dMn] = rec(grid, i + 1, j);
            mx = max(mx, max(cur * dMx, cur * dMn));
            mn = min(mn, min(cur * dMx, cur * dMn));
        }

        return {dp[i][j][0] = mx, dp[i][j][1] = mn};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        fill(&dp[0][0][0], &dp[0][0][0] + 15 * 15 * 2, UNSET);

        auto [mx, mn] = rec(grid, 0, 0);
        return mx < 0 ? -1 : (int)(mx % MOD);
    }
};
