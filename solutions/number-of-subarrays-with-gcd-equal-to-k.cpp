// https://leetcode.com/problems/number-of-subarrays-with-gcd-equal-to-k

class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        for(int i=0; i<n; i++) {
            int g = 0;
            for(int j=i; j<n; j++) {
                g = __gcd(g, nums[j]);
                if(g == k) ans++;
            }
        }
        return ans;
    }
};