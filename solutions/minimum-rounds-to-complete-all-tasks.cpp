// https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks

class Solution {
public:
    int minimumRounds(vector<int>& a) {
        map<int,int> mp;
        for(auto x:a) mp[x]++;
        int ans=0;
        for(auto it:mp) {
            if(it.second==1) {
                return -1;
            }
            ans+=(it.second+2)/3;
        }
        return ans;
    }
};