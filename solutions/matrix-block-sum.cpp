// https://leetcode.com/problems/matrix-block-sum

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& a, int k) 
    {
        // prefix sum over matrix   
        // NOTE: Always make prefix sum n+1 size matrix
        int m = a.size(), n = a[0].size();
        
        vector<vector<int>> sum(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                sum[i][j] = a[i-1][j-1] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
            }
        }
        
        vector<vector<int>> ans(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int x1 = max(0,i-k), x2 = min(m-1,i+k);
                int y1 = max(0,j-k), y2 = min(n-1,j+k);
                // sum start with 1 hence ++
                x1++,x2++,y1++,y2++;
                
                ans[i][j] = sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1];
            }
        }
        
        return ans;
    }
};