// https://leetcode.com/problems/node-with-highest-edge-score

class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> ans(n,0);
        for(int i=0;i<n;i++) {
            ans[edges[i]]+=i;
        }
        int mx = 0;
        for(int i=1;i<n;i++) {
            if(ans[mx]<ans[i])
                mx = i;
        }
        return mx;
    }
};