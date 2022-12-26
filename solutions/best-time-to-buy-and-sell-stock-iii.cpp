// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii

class Solution {
public:
    int rec(int cur, int rem, int buy, vector<int>& prices, vector<vector<vector<int>>> &dp) {
        int n = prices.size();
        
        if(cur==n or rem==0) return 0;
        
        int &ans = dp[cur][rem][buy];
        if(ans != -1) return ans;
        
        ans = rec(cur+1, rem, buy, prices, dp);
        
        if(buy)
            ans = max(ans, -prices[cur] + rec(cur+1, rem, !buy, prices, dp));
        else
            ans = max(ans, prices[cur] + rec(cur+1, rem-1, !buy, prices, dp));
        
        return ans;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(3, vector<int> (2,-1)));
        return rec(0, 2, 1, prices, dp);
    }
}; 