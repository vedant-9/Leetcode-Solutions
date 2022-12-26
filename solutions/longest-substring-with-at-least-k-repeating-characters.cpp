// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters

class Solution {
public:
    int longestSubstring(string s, int k) 
    {
        int n = s.length();
        int mx = 0;
        for(int i=0;i<n;i++)
        {
            map<char,int> m;
            for(int j=1;j<=n-i;j++)
            {
                m[s[i+j-1]]++;
                int f = 1;
                for(auto c:m)
                {
                    if(c.second<k)
                    {
                        f=0;
                        break;
                    }
                }
                if(f)
                    mx = max(mx,j);
            }
        }
        return mx;
    }
};