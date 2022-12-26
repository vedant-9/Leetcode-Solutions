// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid

class Solution {
public:
    int minAddToMakeValid(string s) 
    {
        int n = s.length(), c = 0, ans = 0;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(') c++;
            else c--;
            if(c<0)
            {
                ans += abs(c);
                c = 0;
            }
        }
        ans += abs(c);
        return ans;
    }
};