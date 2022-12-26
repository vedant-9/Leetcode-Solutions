// https://leetcode.com/problems/count-number-of-nice-subarrays

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        
        for(auto &x: nums) x%=2;
        for(int i=1; i<n; i++) nums[i]+=nums[i-1];
        
        unordered_map<int, int> mp;
        mp[0] = 1;
        for(int i=0; i<n; i++) {
            if(nums[i] >= k) {
                ans += mp[nums[i]-k];
            }
            mp[nums[i]]++;
        }
        
        return ans;
    }
};