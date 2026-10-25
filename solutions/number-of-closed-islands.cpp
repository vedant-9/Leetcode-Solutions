class Solution {
public:
    int fill(vector<vector<int>>& g, int i, int j) {
        if (i < 0 or j < 0 or i >= g.size() or j >= g[i].size() or g[i][j])
            return 0;
        g[i][j] = 1;
        return 1 + fill(g, i+1, j) + fill(g, i, j+1) + fill(g, i-1, j) + fill(g, i, j-1);
    }

    int closedIsland(vector<vector<int>>& g) {
        // fill all islands that are connected to edges - make them water
        for (int i = 0; i < g.size(); i++) {
            for (int j = 0; j < g[i].size(); j++) {
                if (i == 0 or j == 0 or i == g.size()-1 or j == g[i].size()-1)
                    fill(g, i, j);
            }
        }

        // fill all remaining islands = closed islands
        int res = 0;
        for (int i = 1; i < g.size()-1; i++)
            for (int j = 1; j < g[i].size()-1; j++)
                res += fill(g, i, j) > 0;
        return res;
    }
};
