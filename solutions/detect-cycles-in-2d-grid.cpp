class Solution {
public:
    bool dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int r, int c, int pr, int pc, char ch) {
        int m = grid.size(), n = grid[0].size();
        if (r < 0 || r >= m || c < 0 || c >= n) return false;
        if (grid[r][c] != ch) return false;
        if (r == pr && c == pc) return false;
        if (visited[r][c]) return true;

        visited[r][c] = true;

        if (r - 1 != pr || c != pc) {
            if (dfs(grid, visited, r - 1, c, r, c, ch))
                return true;
        }
        if (r + 1 != pr || c != pc) {
            if (dfs(grid, visited, r + 1, c, r, c, ch))
                return true;
        }
        if (r != pr || c - 1 != pc) {
            if (dfs(grid, visited, r, c - 1, r, c, ch))
                return true;
        }
        if (r != pr || c + 1 != pc) {
            if (dfs(grid, visited, r, c + 1, r, c, ch))
                return true;
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (dfs(grid, visited, i, j, -1, -1, grid[i][j]))
                        return true;
                }
            }
        }
        return false;
    }
};
