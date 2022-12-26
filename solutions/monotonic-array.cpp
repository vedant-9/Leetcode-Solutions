// https://leetcode.com/problems/monotonic-array

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool inc = true, dec = true;
        for(int i=1; i<n; i++) {
            inc &= (nums[i-1]<=nums[i]);
            dec &= (nums[i-1]>=nums[i]);
        }
        return (inc or dec);
    }
};