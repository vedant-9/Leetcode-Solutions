// https://leetcode.com/problems/shortest-path-visiting-all-nodes

class Solution {
public:
    int solve(vector<vector<int>> &g) {
        int n = g.size();
        int all = (1<<n)-1;
        
        queue<pair<int,pair<int,int>>> q;
        set<pair<int,int>> vis;
        
        for(int i=0;i<n;i++) {
            int mask = (1<<i); // 2^i
            q.push({i,{0,mask}});
            vis.insert({i,mask});
        }
        
        while(!q.empty()) {
            auto node = q.front(); q.pop();
            int val = node.first, dist = node.second.first, mask = node.second.second;
            
            for(auto next:g[val]) {
                int newMask = (mask|(1<<next));
                if(newMask==all) return dist+1;
                else if(vis.count({next,newMask})) continue;
                q.push({next,{dist+1,newMask}});
                vis.insert({next,newMask});
            }
        }
        return 0;
    }
    int shortestPathLength(vector<vector<int>>& g) {
        if(g.size()==1) return 0;
        return solve(g);
    }
};