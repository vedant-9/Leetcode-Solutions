// https://leetcode.com/problems/number-of-enclaves

class Solution {
public:
    int n,m;
    int dfs(vector<vector<int>> &a, int i, int j)
    {
        if(i<0 or j<0 or i>=n or j>=m or a[i][j]!=1)
            return 0;
        a[i][j] = 2;
        return 1+dfs(a,i+1,j)+dfs(a,i-1,j)+dfs(a,i,j+1)+dfs(a,i,j-1);
    }
    
    int numEnclaves(vector<vector<int>>& a) 
    {
        n = a.size(), m = a[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 or j==0 or i==n-1 or j==m-1)
                    dfs(a,i,j);
            }
        }
        
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==1)
                    ans += dfs(a,i,j);
            }
        }
        return ans;
    }
};