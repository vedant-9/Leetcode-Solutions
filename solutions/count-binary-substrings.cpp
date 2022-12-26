// https://leetcode.com/problems/count-binary-substrings

class Solution {
public:
    int countBinarySubstrings(string s) 
    {
        int res = 0;
        int prev = 0, cur = 1;
        for (int i = 1; i < s.length(); i++) 
        {
            // Still in current group
            if (s[i] == s[i - 1]) 
            {
                cur++;
                continue;
            }

            // Start of new group
            res += min(prev, cur); // substring limited by smaller group
            prev = cur;
            cur = 1;
        }
    
    return res + min(prev, cur);
    }
};