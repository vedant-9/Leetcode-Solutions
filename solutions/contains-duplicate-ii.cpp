// https://leetcode.com/problems/contains-duplicate-ii

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        set<int> cand;
        for (int i = 0; i < nums.size(); i++) 
        {
            if (i > k) cand.erase(nums[i-k-1]);
            // .insert returns iterater and bool value if it is inserted or not
            if (!cand.insert(nums[i]).second) return true;
        }
        return false;
    }
};