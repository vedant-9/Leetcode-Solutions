// https://leetcode.com/problems/number-of-subarrays-with-lcm-equal-to-k

class Solution {
public:
    int lcm(int x, int y) {
        return x/(__gcd(x, y))*y;
    }
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        for(int i = 0; i < n; i++) {
            int l = nums[i];
            if(l == k) ans++;
            for(int j = i+1; j < n; j++) {
                if(l > k) break;
                l = lcm(l, nums[j]);
                if(l == k) ans++;
            }
        }
        return ans;
    }
};