// https://leetcode.com/problems/ones-and-zeroes

class Solution {
public:
    int findMaxForm(vector<string>& a, int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(auto &s:a) {
            int z=0,o=0;
            for(auto &ch:s) {
                if(ch=='0') z++;
                else o++;
            }
            // 
            for(int i=m;i>=z;i--) {
                for(int j=n;j>=o;j--) {
                    dp[i][j]=max(dp[i][j],dp[i-z][j-o]+1);
                }
            }
        }
        return dp[m][n];
    }
};