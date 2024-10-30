class Solution {
public:
    vector<int> LIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1); 
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return dp;
    }

    int minimumMountainRemovals(vector<int>& nums) {
        vector<int> inc = LIS(nums);
        reverse(nums.begin(), nums.end());
        vector<int> dec = LIS(nums);
        reverse(dec.begin(), dec.end());
        
        int n = nums.size(), ans = 0;
        for(int i = 1; i < n; i++) {
            if(inc[i] > 1 and dec[i] > 1)
                ans = max(ans, inc[i] + dec[i] - 1);
        }
        
        return n-ans;
    }
};
