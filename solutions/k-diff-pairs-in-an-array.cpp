// https://leetcode.com/problems/k-diff-pairs-in-an-array

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans = 0;
        map<int,int> mp;
        for(auto &x : nums){
            mp[x]++;
        }
        for(auto &x : mp){
            x.second--;
            if(mp.find(x.first+k) != mp.end() and mp[x.first+k] >= 1)
                ans++;
            x.second++;
        }
        return ans;
    }
};