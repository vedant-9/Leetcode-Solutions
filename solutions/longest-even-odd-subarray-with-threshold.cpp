class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int k) {
        int n =  nums.size(), ans = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] & 1 or nums[i] > k) continue;
            int c = 1;
            for(int j = i+1; j < n; j++) {
                if(nums[j]%2 == nums[j-1]%2 or nums[j] > k) break;
                c++;
            }
            ans = max(ans, c);
        }
        return ans;
    }
};
