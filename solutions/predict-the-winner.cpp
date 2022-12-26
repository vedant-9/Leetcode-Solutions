// https://leetcode.com/problems/predict-the-winner

class Solution {
public:
    bool PredictTheWinner(vector<int>& a) {
        int n = a.size();
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {0, 0}));
        for (int i=n-1; i>=0; i--) {
            for (int j=i; j<n; j++) {
                if (i == j)
                    dp[i][j] = {a[i], 0};
                else {
                    dp[i][j].first = max(dp[i][j-1].second+a[j], dp[i+1][j].second+a[i]);
                    dp[i][j].second = min(dp[i][j-1].first, dp[i+1][j].first);
                }
            }
        }
        return dp[0][n-1].first >= dp[0][n-1].second;
    }
};