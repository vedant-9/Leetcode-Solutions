class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (auto x : nums) {
            freq[x]++;
        }

        int dominant = -1;
        for (auto it : freq) {
            if (it.second * 2 > n)
                dominant = it.first;
        }

        if (dominant == -1)
            return -1;

        int left_count = 0, right_count = freq[dominant];
        for (int i = 0; i < n; i++) {
            if (nums[i] == dominant)
                left_count++, right_count--;

            if (left_count * 2 > (i + 1) and right_count * 2 > (n - i - 1))
                return i;
        }

        return -1;
    }
};
