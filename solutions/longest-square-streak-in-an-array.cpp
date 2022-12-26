// https://leetcode.com/problems/longest-square-streak-in-an-array

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        map<int, int> mp;
        for(auto x: nums) mp[x]++;
        
        sort(nums.begin(), nums.end());
        
        int ans = -1;
        for(auto x: nums) {
            if(mp.empty()) break;
            long long cur = x;
            int len = 0;
            while(mp.count(cur)) {
                mp.erase(cur);
                len++;
                cur *= cur;
            }
            if(len>1) ans = max(ans, len);
        }
        
        return ans;
    }
};