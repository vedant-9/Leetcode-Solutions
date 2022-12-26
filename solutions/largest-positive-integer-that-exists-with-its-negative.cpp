// https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        map<int, int> mp;
        for(auto x: nums) mp[x]++;
        int ans = -1;
        for(auto x: nums) {
            if(x>0 and mp[-x]>0) ans = max(ans, x);
        }
        return ans;
    }
};