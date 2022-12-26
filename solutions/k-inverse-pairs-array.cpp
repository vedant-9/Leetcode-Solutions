// https://leetcode.com/problems/k-inverse-pairs-array

class Solution {
public:
    // int dp[1001][1001] = {};
    int kInversePairs(int n, int k) {
        int dp[1001][1001] = {1};
        for(int i=1;i<=n;i++) {
            for(int j=0;j<=k;j++) {
                for(int l=0;l<=min(i-1,j);l++) {
                    dp[i][j] = (dp[i][j]+dp[i-1][j-l])%1000000007;
                }
            }
        }
        return dp[n][k];
        
        // recursive memoized
        // if(k<=0)
        //     return k==0;
        // if(dp[n][k]==0) {
        //     dp[n][k] = 1;
        //     for(int i=0;i<n;i++) {
        //         dp[n][k] = (dp[n][k] + kInversePairs(n-1,k-i))%1000000007;
        //     }
        // }
        // return dp[n][k]-1;
    }
};