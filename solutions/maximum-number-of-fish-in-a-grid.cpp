class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if(i < 0 or j < 0 or i >= m or j >= n or grid[i][j] <= 0) return 0;
        int x = grid[i][j];
        grid[i][j] = -1;
        return x + dfs(grid, i+1, j) + dfs(grid, i-1, j) + dfs(grid, i, j-1) + dfs(grid, i, j+1);
    }
    
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int max_area = 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j] > 0)
                    max_area = max(max_area, dfs(grid, i, j));
        return max_area;
    }
};
