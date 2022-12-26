// https://leetcode.com/problems/rotate-image

class Solution {
public:
    void rotate(vector<vector<int>>& A) 
    {
        int n = A.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                swap(A[i][j],A[j][i]);
            }
        }
        
        for(int j=0;j<n/2;j++)
        {
            for(int i=0;i<n;i++)
            {
                swap(A[i][j],A[i][n-j-1]);
            }
        }
    }
};