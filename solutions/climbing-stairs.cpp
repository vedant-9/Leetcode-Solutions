// https://leetcode.com/problems/climbing-stairs

class Solution {
public:
    
    int dp[50];
    int climbStairs(int n) 
    {
        if(n<=2)
            return n;
        if(dp[n]!=0)
            return dp[n];
        dp[n] = climbStairs(n-1)+climbStairs(n-2);
        return dp[n];
    }
};