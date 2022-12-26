// https://leetcode.com/problems/regions-cut-by-slashes

class Solution {
public:
    int n;
    int rec(vector<vector<int>> &a, int i, int j)
    {
        if(i<0 or j<0 or i>=n or j>=n or a[i][j]!=0)
            return 0;
        a[i][j] = 2;
        return 1+rec(a,i+1,j)+rec(a,i-1,j)+rec(a,i,j-1)+rec(a,i,j+1);
    }
    
    int regionsBySlashes(vector<string>& s) 
    {
        // Divide each cell into 3x3 where middle diagonal represents water / or \
        // and remaining cells represent land
        // Apply dfs on upscaled grid
        
        n = s.size()*3;
        vector<vector<int>> a(n,vector<int>(n,0));
        
        // filling a
        for(int i=0;i<n/3;i++)
        {
            for(int j=0;j<n/3;j++)
            {
                if (s[i][j] == '/') 
                    a[i * 3][j * 3 + 2] = a[i * 3 + 1][j * 3 + 1] = a[i * 3 + 2][j * 3] = 1;
                else if (s[i][j] == '\\') 
                    a[i * 3][j * 3] = a[i * 3 + 1][j * 3 + 1] = a[i * 3 + 2][j * 3 + 2] = 1;
            }
        }
        
        // count land regions
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]==0)
                    rec(a,i,j)?cnt++:0;
            }
        }
        return cnt;
    }
};