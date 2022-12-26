// https://leetcode.com/problems/maximum-star-sum-of-a-graph

class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int X = 1e5+10;
        vector<int> adj[X];
        for(auto x:edges) {
            int a = x[0]; int b = x[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        map<int,vector<int>>mp;
        for(int i=0;i<vals.size();i++) {
            for(auto x:adj[i])
                mp[i].push_back(vals[x]);
        }
        
        int ans = INT_MIN;
        for(int i=0;i<vals.size();i++) {
            auto &x = mp[i];
            sort(x.rbegin(),x.rend());
            int sum = 0;
            int maxi = 0;
            for(int j=0;j<min(k,(int)x.size());j++) {
                sum+=x[j];
                maxi = max(maxi,sum);
            }
            maxi+=vals[i];
            ans = max(ans,maxi);
        }
        return ans;
    }
};