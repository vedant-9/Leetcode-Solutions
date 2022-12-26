// https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up

class Solution {
public:
    int minimumCardPickup(vector<int>& a) {
        map<int,vector<int>> mp;    
        for(int i=0;i<a.size();i++) {
            mp[a[i]].push_back(i);
        }
        int mn = INT_MAX;
        for(auto &it:mp) {
            auto &v=it.second;
            for(int i=1;i<v.size();i++) {
                mn=min(mn,v[i]-v[i-1]+1);
            }
        }
        if(mn==INT_MAX) mn=-1;
        return mn;
    }
};