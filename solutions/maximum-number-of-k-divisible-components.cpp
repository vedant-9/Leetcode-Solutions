class Solution {
public:
    int ans = 0;
    int dfs(int u, vector<vector<int>> &adj, vector<int> &vis, vector<int> &values, int k) {
        int sum = values[u];
        vis[u] = 1;
        for(auto &v: adj[u]) {
            if(!vis[v])
                sum += dfs(v, adj, vis, values, k);
        }
        if(sum % k == 0) {
            ans++;
            return 0;
        }
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);
        for(auto &e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(0, adj, vis, values, k);
        return ans;
    }
};
