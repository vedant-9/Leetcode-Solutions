class Solution {
public:
    int rec(int i, int m, vector<int> &piles, vector<int> &suf, vector<vector<int>> &dp) {
        int n = piles.size();
        if(i >= n) return 0;
        if(i + 2*m >= n) return suf[i];
        if(dp[i][m] != -1) return dp[i][m];
        int ans = 0;
        for(int j = 1; j <= 2*m; j++) {
            ans = max(ans, suf[i] - rec(i+j, max(m, j), piles, suf, dp));
        }
        return dp[i][m] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suf(n, 0);
        suf[n-1] = piles[n-1];
        for(int i = n-2; i >= 0; i--) {
            suf[i] = suf[i+1] + piles[i];
        }
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return rec(0, 1, piles, suf, dp);
    }
};
