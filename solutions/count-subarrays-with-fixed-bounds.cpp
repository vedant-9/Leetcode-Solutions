// https://leetcode.com/problems/count-subarrays-with-fixed-bounds

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        // make partitions at out of bound elements
        // Set outIndex at running out of bound element
        // minK and maxK must be included 
        // Summing all valid subarray counts ending at i over the array -> answer
        int n = nums.size(), outIndex = -1, minKIndex = -1, maxKIndex = -1;
        long long ans = 0;
        for(int i=0; i<n; i++) {
            if(nums[i]<minK or nums[i]>maxK) outIndex = i;
            if(nums[i] == minK) minKIndex = i;
            if(nums[i] == maxK) maxKIndex = i;
            ans += max(0LL, (long long) min(minKIndex, maxKIndex) - outIndex);
        }
        return ans;
    }
};