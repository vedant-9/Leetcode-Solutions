// https://leetcode.com/problems/di-string-match

class Solution {
public:
    vector<int> diStringMatch(string s) 
    {
        vector<int> res;
        for (int l = 0, h = s.size(), i = 0; i <= s.size(); ++i)
            res.push_back(i == s.size() || s[i] == 'I' ? l++ : h--);
        return res;
    }
};