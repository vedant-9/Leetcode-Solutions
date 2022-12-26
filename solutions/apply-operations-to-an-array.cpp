// https://leetcode.com/problems/apply-operations-to-an-array

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        int j = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] == 0) continue;
            if(i == n-1) {
                res[j++] = nums[i]; continue;
            }
            if(nums[i] == nums[i+1]) {
                res[j++] = 2*nums[i];
                nums[i+1] = 0;
            } else {
                res[j++] = nums[i];
            }
        }
        return res;
    }
};