class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> pre_max(n, 0), suf_min(n, 0);
        pre_max[0] = nums[0];
        for(int i = 1; i < n; i++) {
            pre_max[i] = max(pre_max[i-1], nums[i]);
        }
        suf_min[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--) {
            suf_min[i] = min(suf_min[i+1], nums[i]);
        }

        for(int i = 0; i < n; i++) {
            if(pre_max[i] - suf_min[i] <= k) return i;
        }

        return -1;
    }
};
