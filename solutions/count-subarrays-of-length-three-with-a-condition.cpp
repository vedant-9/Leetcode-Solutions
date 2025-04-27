class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        for (int i = 0; i <= n - 3; i++) {
            if (nums[i] + nums[i + 2] == nums[i + 1] / 2.0) {
                count++;
            }
        }

        return count;
    }
};
