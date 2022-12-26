// https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> max_or(n, 0);
        max_or[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--) {
            max_or[i] = (max_or[i+1] | nums[i]);
        }
        
        vector<int> nearest_set(32, -1);
        
        vector<int> ans;
        for(int i=n-1; i>=0; i--) {
            for(int j=0; j<32; j++) {
                if(nums[i] & (1<<j)) 
                    nearest_set[j] = i;
            }
            int farthest_set_index = i;
            for(int j=0; j<32; j++) {
                if(max_or[i] & (1<<j)) 
                    farthest_set_index = max(farthest_set_index, nearest_set[j]);
            }
            ans.push_back(farthest_set_index-i+1);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};