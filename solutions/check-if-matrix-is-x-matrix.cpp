// https://leetcode.com/problems/check-if-matrix-is-x-matrix

class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i==j or i+j+1==n) {
                    if(grid[i][j]==0) return 0;
                } else {
                    if(grid[i][j]!=0) return 0;
                }
            }
        }
        return 1;
    }
};