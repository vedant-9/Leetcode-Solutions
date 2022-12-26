// https://leetcode.com/problems/longest-palindromic-subsequence

class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int g=0;g<n;g++)
        {
            for(int i=0,j=g;j<n;i++,j++)
            {
                if(g==0)
                {
                    dp[i][j] = 1;
                }
                else if(g==1)
                {
                    dp[i][j] = s[i]==s[j]?2:1;
                }
                else
                {
                    if(s[i]==s[j])
                    {
                        dp[i][j] = 2+dp[i+1][j-1];
                    }
                    else
                    {
                        dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};