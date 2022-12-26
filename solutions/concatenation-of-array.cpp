// https://leetcode.com/problems/concatenation-of-array

class Solution {
public:
    vector<int> getConcatenation(vector<int>& a) 
    {
        vector<int> ans;
        for(auto x:a)
            ans.push_back(x);
        for(auto x:a)
            ans.push_back(x);
        return ans;
    }
};