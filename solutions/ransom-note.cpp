// https://leetcode.com/problems/ransom-note

class Solution {
public:
    bool canConstruct(string a, string b)
    {
        unordered_map<char, int> map(26);
        for (int i = 0; i < b.size(); ++i)
            ++map[b[i]];
        for (int j = 0; j < a.size(); ++j)
            if (--map[a[j]] < 0)
                return false;
        return true;
    }
};