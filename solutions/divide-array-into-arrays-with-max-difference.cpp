class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i < n; i+=3) {
            vector<int> tmp = {nums[i], nums[i+1], nums[i+2]};
            if(nums[i+2] - nums[i] > k) return {};
            ans.push_back(tmp);
        }
        return ans;
    }
};
