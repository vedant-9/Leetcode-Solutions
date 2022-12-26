// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced

class Solution
{
public:
    int minSwaps(string s)
    {
        int ans = 0;
        int n = s.length();
        int i = 0, j = n-1;
        int l = 0, r = 0;
        
        while(i<j)
        {
            while(i<j)
            {
                if(s[i]=='[')
                    l++;
                else
                    l--;
                if(l<0)
                    break;
                i++;
            }
            
            while(i<j)
            {
                if(s[j]==']')
                    r++;
                else
                    r--;
                if(r<0)
                    break;
                j--;
            }
            
            if(i<j)
            {
                swap(s[i],s[j]);
                l+=2,r+=2;
                i++;
                j--;
                ans++;
            }
        }
        return ans;
    }
};