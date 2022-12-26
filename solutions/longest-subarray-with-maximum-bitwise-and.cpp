// https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(),nums.end());
        
        int maxLen = 1, i = 0;
        while(i<n) {
            while(i<n and nums[i]!=mx) i++;
            int curLen = 0;
            while(i<n and nums[i]==mx) i++, curLen++;
            maxLen = max(maxLen, curLen);
        }
        return maxLen;
    }
};