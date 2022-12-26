// https://leetcode.com/problems/minimum-moves-to-convert-string

class Solution {
public:
    int minimumMoves(string s) 
    {
        int ans = 0, c = 0,n = s.length();
        for(int i=0;i<n-2;i++)
        {
            if(s[i]=='X')
            {
                s[i] = s[i+1] = s[i+2] = 'O';
                ans++;
            }
        }
        if(s[n-1]=='X' or s[n-2]=='X' and s[n-3]!='X')
            ans++;
        return ans;
    }
};