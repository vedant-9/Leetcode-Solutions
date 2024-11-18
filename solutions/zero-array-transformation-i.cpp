class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> freq(n+1, 0);
        for(int i = 0; i < queries.size(); i++) {
            freq[queries[i][0]]++;
            freq[queries[i][1]+1]--;
        }
        
        int pre_sum = 0;
        for(int i = 0; i < n; i++) {
            pre_sum += freq[i];
            if(pre_sum < nums[i]) return false;
        }
        return true;
    }   
};
