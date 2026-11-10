class Solution {
public:
    long long rec(int j, int &n, vector<int>& costs, vector<long long> &dp) {
        if(j >= n) return 0;
        if(j == n-1) return 0;
        if(dp[j+1] != -1) return dp[j+1];
        long long ans = LLONG_MAX;
        if(j+1 < n)
            ans = min(ans, rec(j+1, n, costs, dp) + costs[j+1] + 1);
        if(j+2 < n)
            ans = min(ans, rec(j+2, n, costs, dp) + costs[j+2] + 4);
        if(j+3 < n)
            ans = min(ans, rec(j+3, n, costs, dp) + costs[j+3] + 9);
        return dp[j+1] = ans;
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n+1, -1);
        return rec(-1, n, costs, dp);
    }
};
