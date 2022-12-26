// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph

class Solution {
public:
    vector<vector<int>> adj;
    vector<int> vis;
    
    int dfs(int cur) {
        vis[cur]=1;
        int nodes=0;
        for(auto next:adj[cur]) {
            if(!vis[next]) nodes+=dfs(next);
        }
        return nodes+1;
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long ans=0;
        adj.resize(n);
        vis.resize(n,0);
        for(auto e:edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int c=0;
        vector<int> v;
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                v.push_back(dfs(i));
                c++;
            }
        }
        long long sum=0;
        for(auto x:v) sum+=x;
        for(auto x:v) {
            ans+=((sum-x)*x);
        }
        return ans/2;
    }
};