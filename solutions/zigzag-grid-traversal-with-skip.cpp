class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(i & 1) {
                int j = m % 2 == 0 ? m-1: m-2;
                while(j >= 0) {
                    ans.push_back(grid[i][j]);
                    j -= 2;
                }
            } else {
                int j = 0;
                while(j < m) {
                    ans.push_back(grid[i][j]);
                    j += 2;
                }
            }
        }
        return ans;
    }
};
