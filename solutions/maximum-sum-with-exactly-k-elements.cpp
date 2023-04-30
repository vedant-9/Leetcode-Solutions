class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return k*(k-1)/2+k*(*nums.rbegin());
    }
};
