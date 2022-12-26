// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int tar) 
    {
        // treat the matrix as an array, just taking care of indices
        // [0..n*m]
        // (row, col) -> row*n + col
        // i -> [i/n][i%n]
        
        if(a.empty() || a[0].empty())
        {
            return false;
        }
        
        int m = a.size(), n = a[0].size();
        int start = 0, end = m*n - 1;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            int e = a[mid/n][mid%n];
            if(tar < e)
            {
                end = mid - 1;
            }
            else if(tar > e)
            {
                start = mid + 1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};


