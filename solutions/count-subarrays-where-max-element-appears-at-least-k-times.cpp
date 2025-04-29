class Solution {
public:
    long long countSubarrays(std::vector<int>& nums, int k) {
        int max_val = 0;
        int n = nums.size();

        for (int num : nums) {
            max_val = max(max_val, num);
        }

        int left = 0;
        long long maxOccur = 0;
        long long count = 0;
        for (int right = 0; right < n; right++) {
            if (nums[right] == max_val) {
                maxOccur++;
            }
            while (maxOccur >= k) {
                if (nums[left] == max_val) {
                    maxOccur--;
                }
                left++;
            }
            count += left;
        }
        return count;
    }
};
