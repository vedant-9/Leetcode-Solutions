// https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph

class Solution {
public:
    void dfs(int cur, int x, vector<vector<int>> &ans, vector<vector<int>>&adj) {
        for(auto next:adj[cur]) {
            if(!ans[next].size() or ans[next].back()!=x) {
                ans[next].push_back(x);
                dfs(next,x,ans,adj);   
            }
        }
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // DFS on each node x
        // For every node ch that is found after node x in dfs, add x as parent of ch
        vector<vector<int>> ans(n),adj(n);
        for(auto e:edges) {
            adj[e[0]].push_back(e[1]);
        }
        for(int i=0;i<n;i++) {
            dfs(i,i,ans,adj);
        }
        return ans;
    }
};