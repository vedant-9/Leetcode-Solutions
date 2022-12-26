// https://leetcode.com/problems/coin-change

typedef long long ll;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<ll> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for(int i=1; i<=amount; i++) {
            for (auto x: coins) {
                if (i-x >= 0)
                    dp[i] = min(dp[i], dp[i-x]+1); 
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};