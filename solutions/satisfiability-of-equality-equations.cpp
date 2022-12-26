// https://leetcode.com/problems/satisfiability-of-equality-equations

class Solution {
public:
    bool dfs(int cur, int dest, vector<vector<int>> &adj, vector<bool> &vis) {
        vis[cur] = true;
        if(cur == dest) return true;
        for(auto &next: adj[cur]) {
            if(!vis[next]) {
                if(dfs(next, dest, adj, vis)) return true;
            }
        }
        return false;
    }
    bool equationsPossible(vector<string>& equations) {
        vector<vector<int>> adj(26);
        for(auto &e: equations) {
            if(e[1] == '=') {
                adj[e[0]-'a'].push_back(e[3]-'a');
                adj[e[3]-'a'].push_back(e[0]-'a');
            }
        }
        
        for(auto &e: equations) {
            if(e[1] == '!') {
                vector<bool> vis(26, 0);
                if(e[0] == e[3] or dfs(e[0]-'a', e[3]-'a', adj, vis)) {
                    return false;
                }
            }
        }
        return true;
    }
};