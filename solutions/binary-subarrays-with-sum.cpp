class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // prefix cnt of 1's
        int n = nums.size(), cnt = 0, cur_sum = 0;
        map<int, int> mp;
        mp[0] = 1;
        for(auto x: nums) {
            cur_sum += x;
            cnt += mp[cur_sum-goal];
            mp[cur_sum]++;
        }
        return cnt;
    }
};
