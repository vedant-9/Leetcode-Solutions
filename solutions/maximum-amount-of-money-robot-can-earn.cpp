class Solution {
public:
    int m, n;
    long dp[501][501][3];
    long rec(int i, int j, int rem, vector<vector<int>> &coins) {
        if(i >= m or j >= n) 
            return INT_MIN;

        if(i == m - 1 && j == n - 1){
            if(rem > 0 && coins[i][j] < 0)    
                return 0;
            else
                return coins[i][j];
        }

        if(dp[i][j][rem] != INT_MIN) 
            return dp[i][j][rem];

        long ans = INT_MIN;
        
        // move right
        if(coins[i][j] >= 0) ans = max(ans, coins[i][j] + rec(i, j+1, rem, coins));
        else {
            // robber steals
            ans = max(ans, coins[i][j] + rec(i, j+1, rem, coins));

            // neutralize robber
            if(rem > 0) 
                ans = max(ans, rec(i, j+1, rem-1, coins));
        }

        // move down
        if(coins[i][j] >= 0) ans = max(ans, coins[i][j] + rec(i+1, j, rem, coins));
        else {
            // robber steals
            ans = max(ans, coins[i][j] + rec(i+1, j, rem, coins));

            // neutralize robber
            if(rem > 0) 
                ans = max(ans, rec(i+1, j, rem-1, coins));
        }


        return dp[i][j][rem] = ans;
    }
    int maximumAmount(vector<vector<int>>& coins) {
        m = coins.size(), n = coins[0].size();
        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                for(int k = 0; k < 3; k++) 
                    dp[i][j][k] = INT_MIN;
            }
        }
        
        return rec(0, 0, 2, coins);
    }
};
