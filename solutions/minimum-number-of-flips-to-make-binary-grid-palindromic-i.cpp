class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans1 = 0, ans2 = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m/2; j++) {
                if(grid[i][j] != grid[i][m-j-1]) ans1++;
            }
        }
        for(int j = 0; j < m; j++) {
            for(int i = 0; i < n/2; i++) {
                if(grid[i][j] != grid[n-i-1][j]) ans2++;
            }
        }
        return min(ans1, ans2);
    }
};
