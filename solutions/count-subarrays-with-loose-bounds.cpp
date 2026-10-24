class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res = 0, cnt = 0;
        for (auto x : nums) {
            if (minK <= x && x <= maxK) {
                cnt += 1;
                res += cnt;
            } else {
                cnt = 0;
            }
        }
        return res;
    }
};
