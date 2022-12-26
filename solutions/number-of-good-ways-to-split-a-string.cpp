// https://leetcode.com/problems/number-of-good-ways-to-split-a-string

class Solution {
public:
    int numSplits(string s) 
    {
        int n = s.length();
        int m[26] = {0};
        for(int i=0;i<n;i++)
        {
            m[s[i]-'a']++;
        }
        
        int ans = 0;
        
        int l[26] = {0};
        for(int i=0;i<n-1;i++)
        {
            l[s[i]-'a']++;
            m[s[i]-'a']--;
            int c1=0,c2=0;
            for(int j=0;j<26;j++)
            {
                if(l[j]) c1++;
                if(m[j]) c2++;
            }
            if(c1==c2)
                ans++;
        }
        return ans;
    }
};