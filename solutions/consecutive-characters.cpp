// https://leetcode.com/problems/consecutive-characters

class Solution {
public:
    int maxPower(string s) 
    {
        int mx = 0, i = 0, n = s.length();
        while(i<n)
        {
            char ch = s[i];
            int c = 0;
            while(i<n and ch==s[i])
                i++,c++;
            mx = max(mx,c);
        }
        return mx;
    }
};