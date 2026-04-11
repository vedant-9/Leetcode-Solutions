class Solution {
public:
    const int mod = 1e9 + 7;
    int rec(int idx, int cur, vector<int> &powers, vector<vector<int>> &dp) {
        if (cur == 0) return 1;
        if (idx >= (int)powers.size() || cur < 0) return 0;

        int& total = dp[idx][cur];
        if (total != -1) return total;

        // Use idx
        total = rec(idx + 1, cur - powers[idx], powers, dp) % mod;
        // Skip idx
        total = (total + rec(idx + 1, cur, powers, dp)) % mod;

        return total;
    }

    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(301, vector<int>(301, -1));
        vector<int> powers;
        for (int i = 1; i < 301; i++) {
            int p = pow(i, x);
            if (p > n) break;
            powers.push_back(p);
        }
        return rec(0, n, powers, dp);
    }
};
