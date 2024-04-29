class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        for(int i = 0; i < n; i++) {
            k ^= nums[i];
        }
        return __builtin_popcount(k);
    }
};
