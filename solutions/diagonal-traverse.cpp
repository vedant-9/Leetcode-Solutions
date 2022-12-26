// https://leetcode.com/problems/diagonal-traverse

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int r = 0, c = 0;
        bool up = true;
        
        vector<int> ans;
        
        while(r<m and c<n) {
            if(up) {
                while(r>0 and c<n-1) {
                    ans.push_back(mat[r][c]);
                    r--, c++;
                }
                ans.push_back(mat[r][c]);
                if(c==n-1) r++;
                else c++;
            } else {
                while(r<m-1 and c>0) {
                    ans.push_back(mat[r][c]);
                    r++, c--;
                }
                ans.push_back(mat[r][c]);
                if(r==m-1) c++;
                else r++;
            }
            up = !up;
        }
        
        return ans;
    }
};