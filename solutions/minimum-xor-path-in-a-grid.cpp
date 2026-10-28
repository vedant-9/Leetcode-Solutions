class Solution {
public:
    int ans;
    vector<vector<vector<char>>> vis;

    void rec(int i, int j, int xo, vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (i >= m || j >= n) return;
        xo ^= grid[i][j];
        if (vis[i][j][xo]) return;
        vis[i][j][xo] = 1;
        if (i == m - 1 && j == n - 1) {
            ans = min(ans, xo);
            return;
        }
        rec(i + 1, j, xo, grid);
        rec(i, j + 1, xo, grid);
    }

    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        ans = 1e9;
        vis.assign(m, vector<vector<char>>(n, vector<char>(1024, 0)));
        rec(0, 0, 0, grid);
        return ans;
    }
};
