// https://leetcode.com/problems/delete-and-earn

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<int> memo(nums.size(), -1);
        return helper(nums, 0, memo);
    }
    
    int helper(vector<int>& nums, int start, vector<int> &memo)
    {
        if(start == nums.size()) return 0;
        
        if(memo[start] == -1)
        {
            int earned = nums[start];
            int skip = start + 1;
            
            while(skip < nums.size() && nums[skip] == nums[start])
            {
                skip++;
                earned += nums[start];
            }
            
            while(skip < nums.size() && nums[skip] == nums[start] + 1) 
                skip++;
            
            earned += helper(nums, skip, memo);
            
            int skipped = helper(nums, start+1, memo);

            memo[start] = max(earned, skipped);
        }
        return memo[start];
    }
};