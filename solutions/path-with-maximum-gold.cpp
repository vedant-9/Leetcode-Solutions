class Solution {
public:
    int rec(int i, int j, vector<vector<int>>& grid) {
        if(i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size() or !grid[i][j]) return 0;
        int cur = grid[i][j], mx = 0;
        grid[i][j] = 0;
        mx = max(mx, rec(i-1, j, grid));
        mx = max(mx, rec(i, j-1, grid));
        mx = max(mx, rec(i+1, j, grid));
        mx = max(mx, rec(i, j+1, grid));
        grid[i][j] = cur;
        return mx+cur;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int mx = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                mx = max(mx, rec(i, j, grid));
            }
        }
        return mx;
    }
};
