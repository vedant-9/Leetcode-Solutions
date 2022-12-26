// https://leetcode.com/problems/continuous-subarray-sum

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> seen = {{0, -1}};
        int cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur =  k ? (cur + nums[i]) % abs(k) : cur + nums[i];
            seen.insert({cur, i});
            if (i - seen[cur] > 1) return true;
        }
        return false;
    }
};