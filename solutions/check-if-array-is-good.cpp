class Solution {
public:
    bool isGood(vector<int>& nums) {
        int sz = nums.size();
        int mx = *max_element(nums.begin(), nums.end());

        if(sz != mx + 1) return false;

        vector<int> cnt(mx, 0);
        for (auto x : nums) {
            cnt[x - 1]++;
        }
        for (int i = 0; i < mx - 1; i++) {
            if (cnt[i] != 1)
                return false;
        }
        return (cnt[mx - 1] == 2);
    }
};
