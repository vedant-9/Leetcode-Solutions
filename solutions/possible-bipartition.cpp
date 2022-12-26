// https://leetcode.com/problems/possible-bipartition

class Solution {
    unordered_map <int, int> color;
    vector<int> adj[2005];
    
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        for(const vector<int> &d: dislikes) {
            adj[d[0]].emplace_back(d[1]);
            adj[d[1]].emplace_back(d[0]);
        }
        
        for(int i = 1; i <= n; i++) {
            queue<int> q;
            q.push(i);
            color.insert({i, 0});
            
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                
                for(auto neighbour:adj[node]) {
                    // all neighbors of current node are given alternate color
                    int altColor = color[node]^1;
                    if(color.find(neighbour) == color.end()) color.insert({neighbour, altColor});
                    else if(color[neighbour] == altColor) continue;
                    else return false;
                    q.push(neighbour);
                }
            }
        }
        return true;
    }
};
