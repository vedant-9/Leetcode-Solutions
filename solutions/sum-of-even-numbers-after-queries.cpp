// https://leetcode.com/problems/sum-of-even-numbers-after-queries

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        for(auto &x: nums) {
            if(x%2 == 0)
                sum += x;
        }
        
        vector<int> ans;
        for(auto &q: queries) {
            int i = q[1], val = q[0];
            if(nums[i]%2 == 0) {
                if(val%2 == 0) sum += val;
                else sum -= nums[i];
            } else {
                if(val%2 != 0) sum += (nums[i]+val);
            }
            nums[i] += val;
            ans.push_back(sum);
        }
        
        return ans;
    }
};