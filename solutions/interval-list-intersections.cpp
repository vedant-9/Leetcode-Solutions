// https://leetcode.com/problems/interval-list-intersections

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        vector<vector<int>> res;
        for (auto i = 0, j = 0; i < A.size() && j < B.size();)
        {
            // first y < second x do i++
            if (A[i][1] < B[j][0])
                ++i;
            // second y < first x do j++
            else if (B[j][1] < A[i][0])
                ++j;
            else
            {
                // max of x and min of y
                res.push_back({max(A[i][0], B[j][0]), min(A[i][1], B[j][1])});
                
                // first y < second y do i++ else j++
                if (A[i][1] < B[j][1])
                    ++i;
                else
                    ++j;
            }
        }
        return res;
    }
};