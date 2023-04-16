class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0), preSum(n, 0), preMax(n, 0), res(n, 0);
        preSum[0] = preMax[0] = nums[0];
        for(int i = 1; i < n; i++) {
            preSum[i] = preSum[i-1] + nums[i];
            preMax[i] = max(preMax[i-1],(long long) nums[i]); 
        }
        ans[0] = 2*nums[0];
        for(int i = 1; i < n; i++) {
            ans[i] = nums[i]+preMax[i];
        }
        res[0] = 2*nums[0];
        for(int i = 1; i < n; i++) {
            res[i] = res[i-1] + ans[i];
        }
        return res;
    }
};
