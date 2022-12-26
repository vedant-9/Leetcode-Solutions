// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        long long maxSum = 0, sum = 0;
        
        map<int, int> cnt;
        for(int i=0; i<k; i++) {
            cnt[nums[i]]++;
            sum += nums[i];
        }
        
        if(cnt.size() == k) {
            maxSum = sum;
        }
        
        for(int i=k; i<n; i++) {
            cnt[nums[i-k]]--;
            cnt[nums[i]]++;
            sum -= nums[i-k];
            sum += nums[i];
            if(cnt[nums[i-k]] == 0) cnt.erase(nums[i-k]);
            if(cnt.size() == k) {
                maxSum = max(maxSum, sum);
            }
        }
        
        return maxSum;
    }
};