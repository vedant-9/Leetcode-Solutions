// https://leetcode.com/problems/majority-element-ii

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> m; for(auto x:nums) m[x]++;
        vector<int> res; 
        for(auto it:m) if(it.second>nums.size()/3) res.push_back(it.first);
        return res;
    }
};