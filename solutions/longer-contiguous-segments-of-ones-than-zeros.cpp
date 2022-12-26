// https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros

class Solution {
public:
    bool checkZeroOnes(string s) 
    {
        int mx0 = 0, mx1 = 0, c0 = 0, c1 = 0;
        if(s[0]=='0') c0++,mx0++;
        else c1++,mx1++;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]==s[i-1])
            {
                if(s[i]=='0') c0++;
                else c1++;
            }
            else
            {
                if(s[i]=='0') c1=0,c0=1;
                else c0=0,c1=1;
            }
            mx0 = max(mx0,c0);
            mx1 = max(mx1,c1);
        }
        return mx1>mx0;
    }
};