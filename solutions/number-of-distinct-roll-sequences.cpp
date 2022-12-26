// https://leetcode.com/problems/number-of-distinct-roll-sequences

class Solution {
public:
    int dp[10001][7][7] = {};
    int distinctSequences(int n, int p = 0, int pp = 0) {
        if (n == 0)
            return 1;
        if (dp[n][p][pp] == 0)
            for (int d = 1; d < 7; ++d)
                if (d != p && d != pp && (p == 0 || gcd(d, p) == 1))
                    dp[n][p][pp] = (dp[n][p][pp] + distinctSequences(n - 1, d, p)) % 1000000007;
        return dp[n][p][pp];
    }
};