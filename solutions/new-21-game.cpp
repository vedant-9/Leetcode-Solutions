class Solution {
public:
    double new21Game(int n, int k, int w) {
        if (k == 0 || n >= k + w) return 1.0;
        vector<double> dp(n + 1);
        dp[0] = 1.0;
        double cur_sum = 1.0, res = 0.0;
        for (int i = 1; i <= n; i++) {
            dp[i] = cur_sum / w;
            if (i < k)
                cur_sum += dp[i];
            else
                res += dp[i];
            if (i - w >= 0) cur_sum -= dp[i - w];
        }
        return res;
    }
};
