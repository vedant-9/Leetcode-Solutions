class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i - 1] + 1 == nums[i])
                cnt++;
            else
                cnt = 0;
            if(i < k-1) continue;
            if (cnt >= k - 1)
                ans.push_back(nums[i]);
            else 
                ans.push_back(-1);
        }
        return ans;
    }
};
