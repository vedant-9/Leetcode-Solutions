class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int mn_sum = 1e9, n = nums.size();
        for(int i = 0; i < n; i++) {
            int cur_sum = 0, len = 0;
            for(int j = i; j < n; j++) {
                cur_sum += nums[j];
                len++;
                if(len > r) break;
                if(len >= l) {
                    if(cur_sum > 0)
                        mn_sum = min(mn_sum, cur_sum);
                }
            }
        }
        if(mn_sum == 1e9) return -1;
        return mn_sum;
    }
};
