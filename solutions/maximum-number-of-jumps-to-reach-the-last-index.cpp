class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[n-1] = 0;
        for(int i = n-2; i >= 0; i--) {
            int mx = -1;
            for(int j = i; j < n; j++) {
                if(abs(nums[j] - nums[i]) <= target)
                    mx = max(mx, dp[j]);
            }
            if(mx != -1) dp[i] = mx+1;
        }
        return dp[0];
    }
};
