// https://leetcode.com/problems/min-cost-climbing-stairs

class Solution {
public:
    
    int minCostClimbingStairs(vector<int>& C) 
    {
        int n = C.size();
        vector<int> dp(n,INT_MAX);
        dp[0] = C[0];
        dp[1] = C[1];
        
        for(int i=2;i<n;i++)
        {
            dp[i] = C[i] + min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
};