// https://leetcode.com/problems/fibonacci-number

class Solution {
public:
    int dp[50];
    int fib(int n) 
    {
        if(n<=1)
            return n;
        if(dp[n]!=0)
            return dp[n];
        dp[n] = fib(n-1)+fib(n-2);
        return dp[n];
    }
};