class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0, val = 0;
        map<int, long long> mp;
        mp[val] = 1;
        for(auto x: nums) {
            val ^= x;
            mp[val]++;
        }
        for(auto it: mp) {
            ans += (it.second-1)*(it.second)/2;
        }
        return ans;
    }
};
