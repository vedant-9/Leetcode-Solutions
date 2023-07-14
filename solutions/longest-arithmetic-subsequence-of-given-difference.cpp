class Solution {
public:
    int longestSubsequence(vector<int>& a, int d) {
        map<int, int> dp;
        int res = 1;
        for(auto x: a) {
            dp[x] = 1 + dp[x-d];
            res = max(res, dp[x]);
        }
        return res;
    }
};
