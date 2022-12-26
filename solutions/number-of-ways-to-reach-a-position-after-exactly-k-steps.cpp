// https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps

class Solution {
public:
    const int mod = 1e9+7;
    // 1000+1000 and 1-1000 => -1000 to 2000
    // offset by +1000 to get into +ve
    int dp[3050][1005];
    
    int rec(int cur, int rem, int end) {
        if(abs(end-cur)>rem) return 0;
        if(cur==end and rem==0) return 1;
        if(rem==0) return 0;
        if(dp[cur+1000][rem]!=-1) return dp[cur+1000][rem];
        return dp[cur+1000][rem]=(rec(cur-1, rem-1, end) + rec(cur+1, rem-1, end))%mod;
    }
    
    int numberOfWays(int start, int end, int k) { 
        memset(dp, -1, sizeof(dp));
        return rec(start, k, end);
    }
};