class Solution {
public:
    bool isZeroArray(vector<int> &nums,  vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<int> freq(n+1, 0);
        for(int i = 0; i < k; i++) {
            freq[queries[i][0]] += queries[i][2];
            freq[queries[i][1]+1] -= queries[i][2];
        }
        
        int pre_sum = 0;
        for(int i = 0; i < n; i++) {
            pre_sum += freq[i];
            if(pre_sum < nums[i]) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int low = 0, high = queries.size()+1;
        while(low < high) {
            int mid = low + (high-low)/2;
            if(isZeroArray(nums, queries, mid)) high = mid;
            else low = mid+1;
        }
        if(high > queries.size()) return -1;
        return high;
    }
};

