class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[2], e[1]});  // {weight, v}
        }

        // dist[node][run] = shortest distance to reach node with a streak of `run` equal labels
        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));

        // {distance, node, run}
        using T = tuple<int,int,int>;
        priority_queue<T, vector<T>, greater<>> pq;

        dist[0][1] = 0;  // start: streak is just node 0 itself
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, run] = pq.top(); pq.pop();
            if (d > dist[u][run]) continue;  // stale entry
            if (u == n - 1) return d;        // first pop of target is the answer

            for (auto [w, v] : adj[u]) {
                // same label extends the streak, different label resets it
                int newRun = (labels[v] == labels[u]) ? run + 1 : 1;
                if (newRun > k) continue;    // streak too long, invalid move

                if (d + w < dist[v][newRun]) {
                    dist[v][newRun] = d + w;
                    pq.push({dist[v][newRun], v, newRun});
                }
            }
        }
        return -1;
    }
};
