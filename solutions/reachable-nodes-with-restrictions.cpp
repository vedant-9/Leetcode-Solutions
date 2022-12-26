// https://leetcode.com/problems/reachable-nodes-with-restrictions

class Solution {
public:
    int dfs(int cur, vector<vector<int>> &adj, vector<int> &vis) {
        vis[cur] = 1;
        int total = 1;
        for(auto next: adj[cur]) {
            if(!vis[next]) {
                total += dfs(next,adj,vis);
            }
        }
        return total;
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> adj(n+1);
        for(auto e:edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> vis(n+1,0);
        for(auto x: restricted)
            vis[x] = 1;
        return dfs(0,adj,vis);
    }
};