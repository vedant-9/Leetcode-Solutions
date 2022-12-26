// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Stores index where next swap is done
        int k = 0;
        int n = nums.size();
        int i = 0;
        while (i < n) {
			// Swap at max two same elements
            swap(nums[k++], nums[i++]);
            if (i < n && nums[i] == nums[k - 1]) {
                swap(nums[k++], nums[i++]);
            }
			// Find next unique element
            while (i < n && nums[k - 1] == nums[i])
                i++;
        }
        return k;
    }
};