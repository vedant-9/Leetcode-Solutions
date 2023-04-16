class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int> ans;
        int m = grid.size(), n = grid[0].size();
        for(int j = 0; j<n; j++) {
            int mx = 0;
            for(int i = 0; i<m; i++) {
                mx = max(mx, (int) to_string(abs(grid[i][j])).length() + (grid[i][j]<0));
            }
            ans.push_back(mx);
        }
        return ans;
    }
};
