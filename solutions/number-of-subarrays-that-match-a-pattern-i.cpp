class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pat) {
        int n = nums.size(), m = pat.size(), ans = 0;
        for(int i = 0; i < n-m; i++) {
            int flag = 0;
            for(int j = 0; j < m; j++) {
                if(!((nums[i+j] < nums[i+j+1] and pat[j] == 1) or (nums[i+j] == nums[i+j+1] and pat[j] == 0) or (nums[i+j] > nums[i+j+1] and pat[j] == -1))) {
                    flag = 1; break;
                }
                    
            }
            if(!flag) ans++;
        }
        return ans;
    }
};
