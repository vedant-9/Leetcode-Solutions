class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n, vector<int> (m, -1));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    ans[i][j] = 0;
                    q.push({i, j});
                } 
            }
        }

        int lvl = 1;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto cur = q.front();
                q.pop();
                int x = cur.first, y = cur.second;
                if(x+1 < n and ans[x+1][y] == -1) ans[x+1][y] = lvl, q.push({x+1, y});
                if(x-1 >= 0 and ans[x-1][y] == -1) ans[x-1][y] = lvl, q.push({x-1, y}); 
                if(y+1 < m and ans[x][y+1] == -1) ans[x][y+1] = lvl, q.push({x, y+1}); 
                if(y-1 >= 0 and ans[x][y-1] == -1) ans[x][y-1] = lvl, q.push({x, y-1}); 
            }
            

            lvl++;
        }

        return ans;
    }
};
