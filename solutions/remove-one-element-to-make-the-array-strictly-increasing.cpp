// https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) 
    {
        int previous = nums[0];
        bool used = false;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] <= previous)
            { 
                // it's not strictly increasing
                if (used)
                    return false;
                
                // we haven't used the element removal yet.
                used = true;
                // we remove the element from i - 1 position because it's bigger, so we update previous.
                if (i == 1 || nums[i] > nums[i - 2]) 
                    previous = nums[i];
                // else we remove current element and leave previous to it's existing value.
            } 
            else
                previous = nums[i];
        }
        return true;
    }
};