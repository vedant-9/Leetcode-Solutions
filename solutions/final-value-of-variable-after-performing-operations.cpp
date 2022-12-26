// https://leetcode.com/problems/final-value-of-variable-after-performing-operations

class Solution {
public:
    int finalValueAfterOperations(vector<string>& ops) 
    {
        int ans = 0;
        for(auto s:ops)
        {
            if(s=="++X" or s=="X++")
                ans++;
            else
                ans--;
        }
        return ans;
    }
};