// https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int> p;
        for(auto x:nums)
            p.push(x);
        
        while(k-->=2) p.pop();
        return p.top();
    }
};