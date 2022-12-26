// https://leetcode.com/problems/network-delay-time

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,1e9);
        dist[k]=0;
        for(int i=0;i<n;i++) {
            for(auto e:times) {
                int u=e[0],v=e[1],w=e[2];
                if(dist[u]+w<dist[v]) dist[v]=dist[u]+w;
            }
        }
        int mx = INT_MIN;
        for(int i=1;i<=n;i++) mx=max(mx,dist[i]);
        if(mx>=1e9) mx=-1;
        return mx;
    }
};