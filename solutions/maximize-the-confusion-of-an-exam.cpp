// https://leetcode.com/problems/maximize-the-confusion-of-an-exam

class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) 
    {
        int n = s.length(), mx = INT_MIN, p = k, t = k, j = 0, l = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='F')
                p--;
            else
                t--;
            while(p<0)
            {
                if(s[j]=='F')
                    p++;
                j++;
            }
            while(t<0)
            {
                if(s[l]=='T')
                    t++;
                l++;
            }
            mx = max({mx,i-j+1,i-l+1});
        }
        return mx;
    }
};