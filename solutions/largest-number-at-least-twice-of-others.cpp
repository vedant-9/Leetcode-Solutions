// https://leetcode.com/problems/largest-number-at-least-twice-of-others

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int first=-1,second=-1;
        int res=-1;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]>first)
            {
                second=first;
                first=nums[i];
                res=i;
            }
            else if(nums[i]>second)
            {
                second=nums[i];
            }
        }
        if(first<2*second)
            return -1;
        return res;
    }
};