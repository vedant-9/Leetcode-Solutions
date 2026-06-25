class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> pre_cnt(n+1, 0);
        for(int i = 0; i < n; i++) {
            pre_cnt[i+1] = pre_cnt[i] + (nums[i] == target);
        }
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(pre_cnt[j+1] - pre_cnt[i] > (j-i+1)/2) cnt++;
            }
        }
        return cnt;
    }
};
