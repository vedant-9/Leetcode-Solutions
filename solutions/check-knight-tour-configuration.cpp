class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        map<int, pair<int, int>> mp;
        int n = grid.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                mp[grid[i][j]] = {i+1, j+1};
            }
        }
        if(mp[0].first != 1 or mp[0].second != 1) return false;
        for(int i = 0; i<n*n-1; i++) {
            int dx = mp[i+1].first - mp[i].first;
            int dy = mp[i+1].second - mp[i].second;
            if(abs(dx)+abs(dy) != 3 or abs(dx) == 3 or abs(dy) == 3) {
                return false;
            }
        }
        return true;
    }
};
