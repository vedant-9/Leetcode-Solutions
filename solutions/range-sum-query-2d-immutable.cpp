// https://leetcode.com/problems/range-sum-query-2d-immutable

class NumMatrix {
public:
    vector<vector<int>> a;
    NumMatrix(vector<vector<int>>& mat) 
    {
        int m = mat.size() , n = mat[0].size();
        a.resize(m+1);
        for(auto &v:a)
            v.resize(n+1);
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                a[i][j] = mat[i-1][j-1] + a[i-1][j] + a[i][j-1] -a[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) 
    {
        r1++,c1++,r2++,c2++;
        return a[r2][c2]-a[r2][c1-1]-a[r1-1][c2]+a[r1-1][c1-1];
    }
};
