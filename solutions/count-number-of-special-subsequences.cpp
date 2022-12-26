// https://leetcode.com/problems/count-number-of-special-subsequences

class Solution {
public:
    int countSpecialSubsequences(vector<int>& A) 
    {
        vector<int> dp = {0, 0, 0};
        int mod = 1e9 + 7;
        for (int& a: A)
            dp[a] = ((dp[a] + dp[a]) % mod + (a > 0 ? dp[a-1] : 1)) % mod;
        return dp[2];
    }
};