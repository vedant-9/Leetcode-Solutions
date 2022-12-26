// https://leetcode.com/problems/interleaving-string

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) 
    {
        // s1 and s2 should be subsequences
        int l,m,n;
        l = s1.length();
        m = s2.length();
        n = s3.length();
        
        if(n!=l+m)
            return false;
        
        bool dp[l+1][m+1];
        for(int i=0;i<=l;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 and j==0)
                    dp[i][j] = 1;
                else if(i==0)
                    dp[i][j] = dp[i][j-1] and s2[j-1]==s3[i+j-1];
                else if(j==0)
                    dp[i][j] = dp[i-1][j] and s1[i-1]==s3[i+j-1];
                else
                    dp[i][j] = ((dp[i][j-1] and s2[j-1]==s3[i+j-1]) || (dp[i-1][j] and s1[i-1]==s3[i+j-1]));
            }
        }
        return dp[l][m];
        
    }
};