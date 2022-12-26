// https://leetcode.com/problems/generate-parentheses

class Solution {
public:

    vector<string> res;
    
    void addpar(string s, int open, int close, int n)
    {
        if(open==n and close==n)
        {
            res.push_back(s);
            return;
        }
        // open can fit 
        if(open<n) 
            addpar(s+"(",open+1,close,n);
        
        // close can fit until less than open
        if(close<open) 
            addpar(s+")",open,close+1,n);
    }
    
    vector<string> generateParenthesis(int n) 
    {
        addpar("", 0, 0, n);
        reverse(res.begin(),res.end());
        return res;
    }
};