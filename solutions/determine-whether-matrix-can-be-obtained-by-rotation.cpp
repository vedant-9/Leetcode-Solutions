// https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation

class Solution {
public:
    bool check(vector<vector<int>> &mat,vector<vector<int>> &tar)
    {
        int n = mat.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]!=tar[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& tar) 
    {
        int n = mat.size();
        int f = 0;
        
        
        for(int x=0;x<4;x++)
        {
            f |= check(mat,tar);
        
         int k;
         for (int i = 0; i < n; i++)
         {
            k = n-1;
             for (int j = 0; j < k; j++)
             {
                swap(mat[i][j], mat[i][k]);
                k--;
             }
         }
        for (int i = 0; i < n; i++)
         for (int j = i; j < n; j++)
         swap(mat[i][j], mat[j][i]);
        }
        return f;
        
    }
};