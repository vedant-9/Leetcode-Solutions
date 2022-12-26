// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    bool canPartition(vector<int>& a) {
        int n = a.size(), sum = 0;
        for(auto x:a) sum+=x;
        if(sum%2!=0) return 0;
        int dp[n+1][sum+1];
        for(int j=0;j<=sum;j++) dp[0][j]=0;
        for(int i=0;i<=n;i++) dp[i][0]=1; 
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=sum;j++) {
                dp[i][j]=dp[i-1][j];
                if(j-a[i-1]>=0) {
                    dp[i][j]=dp[i][j] || dp[i-1][j-a[i-1]];
                }
            }
        }
        return dp[n][sum/2];
    }
};