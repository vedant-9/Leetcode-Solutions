// https://leetcode.com/problems/delete-characters-to-make-fancy-string

class Solution {
public:
    string makeFancyString(string s) 
    {
        string ans = "";
        int n = s.length();
        ans += s[0];
        int c = 1;
        for(int i=1;i<n;i++)
        {
            if(s[i]!=s[i-1])
            {
                c = 1;
                ans += s[i];
            }
            else
            {
                c++;
                if(c<3)
                    ans += s[i];
            }
        }
        return ans;
    }
};