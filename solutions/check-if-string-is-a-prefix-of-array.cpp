// https://leetcode.com/problems/check-if-string-is-a-prefix-of-array

class Solution {
public:
    bool isPrefixString(string s, vector<string>& a) 
    {
        int i = 0;
        int n = s.length();
        int j = 0, k = 0;
        for(;i<n;i++)
        {
            if(k>=a[j].size())
            {
                k = 0;
                j++;
            }
            if(j==a.size())
                break;
            if(s[i]!=a[j][k])
                break;
            k++;
        }
        return (i==n && k == a[j].size());
    }
};