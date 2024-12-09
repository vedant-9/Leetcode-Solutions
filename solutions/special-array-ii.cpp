class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> pre_sum(n+1, 0);
        for(int i = 1; i < n; i++) {
            pre_sum[i] = pre_sum[i-1] + (nums[i-1]%2 == nums[i]%2);
        }
        vector<bool> ans;
        for(auto q: queries) {
            ans.push_back(pre_sum[q[1]] == pre_sum[q[0]]);
        }
        return ans;
    }
};
