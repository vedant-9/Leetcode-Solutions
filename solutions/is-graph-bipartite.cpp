// https://leetcode.com/problems/is-graph-bipartite

class Solution {
public:
    
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int> color(n); // 0: uncolored; 1: color A; -1: color B

        queue<int> q; // queue, resusable for BFS    

        // For different components
        for (int i = 0; i < n; i++) 
        {
            if (color[i]) continue; // skip already colored nodes

            // BFS with seed node i to color neighbors with opposite color
            color[i] = 1; // color seed i to be A (doesn't matter A or B) 
            q.push(i);
            while(!q.empty())
            {
                int cur = q.front();
                for (int neighbor : graph[cur]) 
                {
                    if (color[neighbor]==0) // if uncolored, color with opposite color
                    { 
                        color[neighbor] = -color[cur]; 
                        q.push(neighbor); 
                    } 
                    else if (color[neighbor] == color[cur]) 
                        return false; // if already colored with same color, can't be bipartite!
                }  
                q.pop();
            }
        }
        return true;
    }
};