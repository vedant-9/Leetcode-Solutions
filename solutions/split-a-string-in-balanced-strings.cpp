// https://leetcode.com/problems/split-a-string-in-balanced-strings

class Solution {
public:
    int balancedStringSplit(string s) 
    {
        int ans = 0,c = 0;
        for(auto ch:s)
        {
            if(ch=='L')
                c++;
            else
                c--;
            if(c==0)
                ans++;
        }
        return ans;
    }
};