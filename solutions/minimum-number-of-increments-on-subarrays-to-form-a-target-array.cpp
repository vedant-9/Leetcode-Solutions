// https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int res = 0, pre = 0;
        for (auto x: target) {
            res += max(x - pre, 0);
            pre = x;
        }
        return res;
    }
};