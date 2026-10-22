class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int zero = find(nums.begin(), nums.end(), 0) - nums.begin();

        int ans = INT_MAX;

        // Walk right from zero: zero, zero+1, zero+2, ... (wrapping)
        if (isSorted(nums, zero, +1)) {
            ans = min(ans, zero);
            ans = min(ans, 1 + (n - zero) + 1);
        }

        // Walk left from zero: zero, zero-1, zero-2, ... (wrapping)
        if (isSorted(nums, zero, -1)) {
            ans = min(ans, 1 + zero + 1);
            ans = min(ans, n - zero);
        }


        return ans == INT_MAX ? -1 : ans;
    }
    bool isSorted(vector<int>& nums, int zero, int step) {
        int n = nums.size();
        int idx = zero;
        for (int i = 1; i < n; i++) {
            int next = idx + step;
            if (next < 0) next += n;      // wrap past the left edge
            if (next >= n) next -= n;     // wrap past the right edge
            if (nums[idx] > nums[next]) return false;
            idx = next;
        }
        return true;
    }
};
