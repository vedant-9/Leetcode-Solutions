class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int res = 0;
        for (int x : nums) {
            res += (mx - x);
        }
        return res;
    }
};
