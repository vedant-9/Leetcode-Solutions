class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int idx1 = 0, idxn = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) idx1 = i;
            if(nums[i] == n) idxn = i;
        }
        return idx1+n-1-idxn-(idx1>idxn);
    }
};
