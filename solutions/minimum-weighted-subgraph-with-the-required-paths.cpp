// https://leetcode.com/problems/minimum-weighted-subgraph-with-the-required-paths

const int N=1e5+5;
vector<pair<int,int>> adj[N],revadj[N];
class Solution {
public:
    int n;
    struct cc{ bool operator()(const pair<long long,long long> &a,const pair<long long,long long> &b)
    {return a.second > b.second;}};
    vector<long long> dijkstra(long long src) {
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,cc> pq;
        vector<bool> vis(n,0); vector<long long> ans(n,LONG_MAX); pq.push({src,0});
        while(!pq.empty()) {
            auto cur=pq.top(); pq.pop();
            if(vis[cur.first]) continue;
            vis[cur.first]=1; ans[cur.first]=cur.second;
            for(auto x:adj[cur.first]) {
                if(!vis[x.first]) pq.push({x.first,cur.second+x.second});
            }
        }
        return ans;
    }
    
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        this->n = n;
        for(int i=0;i<1e5+5;i++) {
            adj[i].clear();
            revadj[i].clear();
        }
        for(auto e:edges) {
            adj[e[0]].push_back({e[1],e[2]});
            revadj[e[1]].push_back({e[0],e[2]});
        }
        auto d1 = dijkstra(src1);
        auto d2 = dijkstra(src2);
        for(int i=0;i<1e5+5;i++) {
            adj[i].clear();
            adj[i]=revadj[i];
        }
        auto d3 = dijkstra(dest);
        long long ans=LONG_MAX;
        for(int i=0;i<n;i++) {
            if(d1[i]==LONG_MAX or d2[i]==LONG_MAX or d3[i]==LONG_MAX) continue;
            ans=min(ans,d1[i]+d2[i]+d3[i]);
        }
        if(ans>=LONG_MAX) ans=-1;
        return ans;
    }
};