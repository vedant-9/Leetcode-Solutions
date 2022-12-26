// https://leetcode.com/problems/search-a-2d-matrix-ii

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& A, int tar) 
    {
        int m = A.size(), n = m ? A[0].size() : 0, r = 0, c = n - 1;
        while (r < m && c >= 0) 
        {
            if (A[r][c] == tar)
                return true;
            A[r][c] > tar ? c-- : r++;
        }
        return false;
    }
};