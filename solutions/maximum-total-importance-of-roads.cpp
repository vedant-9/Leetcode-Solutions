// https://leetcode.com/problems/maximum-total-importance-of-roads

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& adj) {
        vector<long long> cnt(n,0);
        for(auto e:adj) {
            cnt[e[0]]++; cnt[e[1]]++;
        }
        sort(cnt.begin(),cnt.end());
        long long ans=0;
        for(int i=0;i<n;i++) {
            ans+=cnt[i]*(i+1);
        }
        return ans;
    }
};