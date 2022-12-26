// https://leetcode.com/problems/largest-number-after-mutating-substring

class Solution {
public:
    string maximumNumber(string s, vector<int>& v) 
    {
        bool changed = false;
        for (char &c : s) 
        {
            int before = c - '0', after = v[before];
            if (after < before) 
            {
                if (changed) 
                    break;
                continue;
            } 
            else if (after == before) 
            {
                continue;
            }
            changed = true;
            c = '0' + after;
        }
        return s;
    }
};