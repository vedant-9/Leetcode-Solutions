class Graph {
public:
    vector<vector<pair<int,int>>> adj;
    int n;
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        adj.resize(n);
        for(auto &v: adj) adj.clear();
        for(auto &e: edges) adj[e[0]].push_back({e[1], e[2]});
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<bool> vis(n,0); vector<int> ans(n,-1); pq.push({0,node1});
        while(!pq.empty()) {
            auto cur=pq.top(); pq.pop();
            if(vis[cur.second]) continue;
            vis[cur.second]=1; ans[cur.second]=cur.first;
            for(auto x:adj[cur.second]) {
                if(!vis[x.first]) pq.push({cur.first+x.second,x.first});
            }
        }
        return ans[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
