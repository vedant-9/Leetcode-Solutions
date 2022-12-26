// https://leetcode.com/problems/longest-ideal-subsequence

class Solution {
public:
    int longestIdealString(string s, int k) {
        int dp[26] = {0}, res = 0;
        for (auto& x : s) {
            int i = x-'a';
            for (int j = max(i-k,0); j <= min(i+k,25); j++)
                dp[i] = max(dp[i], dp[j]);
            dp[i]++;
            res = max(res, dp[i]);
        }
        return res;
    }
};