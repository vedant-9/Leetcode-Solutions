class Solution {
   public:
    vector<pair<int, int>> directions = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
    map<vector<int>, double> m;
    double dfs(int r, int c, int n, int k) {
        double in = 0;
        if (k == 0) {
            if (r >= 0 && r < n && c >= 0 && c < n) in++;
            return in;
        }
        if (r >= n || c >= n || r < 0 || c < 0) return 0;
        vector<int> v = {r, c, k};
        if (m.find(v) != m.end()) return m[v];
        for (auto it : directions) {
            int dr = r + it.first, dc = c + it.second;
            in += dfs(dr, dc, n, k - 1);
        }
        return m[v] = in;
    }
    double knightProbability(int n, int k, int row, int column) {
        double total = pow(8, k);
        double in = dfs(row, column, n, k);
        double prob = in / total;
        return prob;
    }
};
