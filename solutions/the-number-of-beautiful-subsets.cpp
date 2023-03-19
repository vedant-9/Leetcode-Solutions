class Solution {
public:
    int rec(int idx, unordered_map<int, int> &mp, vector<int> &nums, int k) {
        int n = nums.size();
        if(idx == n) return 1;
        
        // don't take
        int ans = rec(idx+1, mp, nums, k);
        
        // take
        if(!mp[nums[idx]-k]) {
            mp[nums[idx]]++;
            ans += rec(idx+1, mp, nums, k);
            mp[nums[idx]]--;
        }
           
        
        return ans;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        return rec(0, mp, nums, k)-1;
    }
};
