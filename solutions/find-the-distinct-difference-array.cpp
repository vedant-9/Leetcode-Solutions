class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            set<int> st1, st2;
            for(int j = 0; j <= i; j++) st1.insert(nums[j]);
            for(int j = i+1; j < n; j++) st2.insert(nums[j]);
            ans.push_back(st1.size() - st2.size());
        }
        return ans;
    }
};
