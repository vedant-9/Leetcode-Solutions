// https://leetcode.com/problems/subarray-product-less-than-k

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        // simple sliding window
        if (k <= 1) return 0;
        int n = nums.size(), prod = 1, ans = 0, left = 0;
        for (int i = 0; i < n; i++) 
        {
            prod *= nums[i];
            while (prod >= k) 
                prod /= nums[left++];
            ans += i - left + 1;
        }
        return ans;
    }
};