class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int k = nums[0]+1;
        for(int i = 1; i < nums.size();) {
            if(nums[i] != k) ans.push_back(k);
            else i++;
            k++;
        }
        return ans;
    }
};
