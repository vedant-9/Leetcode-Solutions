// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses

class Solution {
public:
    int maxDepth(string s) 
    {
        int ans = 0, c = 0;
        for(auto ch:s)
        {
            if(ch=='(')
                c++;
            else if(ch==')')
                c--;
            if(c>ans)
                ans = c;
        }
        return ans;
    }
};