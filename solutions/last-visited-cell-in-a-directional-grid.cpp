class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int dir[4][2] = {{0,-1}, {0,1}, {-1,0},{1,0}};
        int curx = 0, cury = 0;
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size()));

        while(1) {
            int nx, ny;
            if(grid[curx][cury] == 'L') {
                nx = curx + dir[0][0]; ny = cury + dir[0][1];
            } else if(grid[curx][cury] == 'R') {
                nx = curx + dir[1][0]; ny = cury + dir[1][1];
            } else if(grid[curx][cury] == 'U') {
                nx = curx + dir[2][0]; ny = cury + dir[2][1];
            } else {
                nx = curx + dir[3][0]; ny = cury + dir[3][1];
            }
            
            if(nx <0 or ny < 0 or nx >= grid.size() or ny>=grid[0].size() or vis[nx][ny]) 
                return {curx, cury};

            vis[curx][cury] = 1;
            curx = nx;
            cury = ny;
        }

        return {};
    }
};
