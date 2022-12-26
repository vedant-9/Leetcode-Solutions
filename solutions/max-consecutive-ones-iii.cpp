// https://leetcode.com/problems/max-consecutive-ones-iii

class Solution {
public:
    // TIME COMPLEXITY:- O(N)
    int longestOnes(vector<int>& nums, int k)
    {
        int ans = 0; // maximum answer = longest consecutive ones
        int cnt = 0; // number of zero's in window
        
        // consider window from [l,r] such that at most k 0's can be flipped
        int l = 0;
        for(int r = 0;r<nums.size();r++)
        {
            if(nums[r]==0)
                cnt++;
            while(cnt>k and l<r)
            {
                if(nums[l]==0)
                    cnt--;
                // inc l pointer
                l++;
            }
            
            // [l,r] we have cnt<=k amount of zero's and we can flip all that
            if(cnt<=k)
                ans = max(ans,r-l+1);
        }
        return ans;
    }
};