// https://leetcode.com/problems/minimum-size-subarray-sum

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), minLen = INT_MAX;
        
        vector<int> preSum(n+1, 0);
        for(int i=1; i<=n; i++) {
            preSum[i] = preSum[i-1]+nums[i-1];
        }
        
        for(int i=n; i>=0 and preSum[i]>=target; i--) {
            int j = upper_bound(preSum.begin(), preSum.end(), preSum[i]-target)-preSum.begin();
            minLen = min(minLen, i-j+1);
        }
        
        if(minLen == INT_MAX)
            minLen = 0;
        
        return minLen;
    }
};