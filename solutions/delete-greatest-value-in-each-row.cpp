// https://leetcode.com/problems/delete-greatest-value-in-each-row

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for(auto &v: grid) {
            sort(v.begin(), v.end());
        }
        int ans = 0, m = grid[0].size(), n = grid.size();
        for(int j=0; j<m; j++) {
            int mx = grid[0][j];
            for(int i=0; i<n; i++) {
                mx = max(mx, grid[i][j]);
            }
            ans += mx;
        }
        return ans;
    }
};