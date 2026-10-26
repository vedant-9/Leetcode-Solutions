class Solution {
public:
    long rec(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size() or grid[i][j] <= 0) return 0;
        int x = grid[i][j];
        grid[i][j] = -1;
        return x + rec(grid, i-1, j) + rec(grid, i, j-1) + rec(grid, i+1, j) + rec(grid, i, j+1);
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int cnt = 0;
        for(int i =0 ; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] > 0 and rec(grid, i, j) % k == 0) cnt++; 
            }
        }
        return cnt;
    }
};
