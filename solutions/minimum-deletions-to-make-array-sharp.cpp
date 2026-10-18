class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int osz = nums.size();
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        return osz - nums.size();
    }
};
