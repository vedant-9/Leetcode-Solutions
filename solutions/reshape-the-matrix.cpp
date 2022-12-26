// https://leetcode.com/problems/reshape-the-matrix

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) 
    {
        int m = mat.size(),n = mat[0].size();
        if(m*n!=r*c)
            return mat;
        vector<vector<int>> res(r,vector<int>(c));
        
        int l = 0,k=0;
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(k==n)
                {
                    k = 0;
                    l++;
                }
                res[i][j] = mat[l][k];
                k++;
            }
        }
        return res;
    }
};