// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv

class Solution {
public:
    int rec(int cur, int rem, int buy, vector<int> &prices, vector<vector<vector<int>>> &dp) {
        int n = prices.size();
        
        if(cur == n or rem == 0) return 0;
        
        int &ans = dp[cur][rem][buy];
        if(ans != -1) return ans;
        
        // skip without buying
        ans = rec(cur+1, rem, buy, prices, dp);
        
        // do buy or sell
        if(buy) {
            ans = max(ans, -prices[cur] + rec(cur+1, rem, !buy, prices, dp));
        } else {
            ans = max(ans, prices[cur] + rec(cur+1, rem-1, !buy, prices, dp));
        }
        
        return ans;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        
        if (2*k > n) {
            int res = 0;
            for (int i=1; i<n; i++) {
                res += max(0, prices[i]-prices[i-1]);
            }
            return res;
        }
        
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (k+1, vector<int> (2,-1)));
        return rec(0, k, 1, prices, dp);
    }
};