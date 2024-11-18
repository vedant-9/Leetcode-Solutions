class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int> suf_sum(n, 0);
        suf_sum[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--) {
            suf_sum[i] = suf_sum[i+1]+nums[i];
        }
        
        int pre_sum = 0, ans = 0;
        for(int i = 0; i < n-1; i++) {
            pre_sum += nums[i];
            if(nums[i] == 0) {
                if(pre_sum == suf_sum[i+1]) ans += 2;
                else if(abs(pre_sum - suf_sum[i+1]) == 1) ans++;
            }
        }
        if(pre_sum == 0 and nums[n-1] == 0) ans+=2;
        else if(pre_sum == 1 and nums[n-1] == 0) ans++;
        return ans;
    }
};
