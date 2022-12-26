// https://leetcode.com/problems/letter-case-permutation

class Solution {
public:
    vector<string> letterCasePermutation(string s) 
    {
        vector<string> v;
        vector<int> a;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>='A' && s[i]<='Z')
                s[i] += 32;
            if(s[i]>='a' && s[i]<='z')
                a.push_back(i);
        }
        
        v.push_back(s);
        
        int n = a.size();
        for(int i=1;i<(1<<n);i++)
        {
            string p = s;
            for(int j=0;j<n;j++)
            {
                if(i & (1<<j))
                    p[a[j]] -= 32;
            }
            v.push_back(p);
        }
        
        return v;
    }
};