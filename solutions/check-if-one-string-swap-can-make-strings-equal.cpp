// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal

class Solution {
public:
    // Every time we see a missmatch - store it in an array.
    // In the end, we can eather have zero missmaches, or two mirrored missmatches.
    // Otherwise, we cannot make strings equal.

    bool areAlmostEqual(string s1, string s2) 
    {
        vector<array<char, 2>> mis;
        for (auto i = 0; i < s1.size() && mis.size() < 3; ++i)
            if (s1[i] != s2[i])
                mis.push_back({mis.empty() ? s1[i] : s2[i], mis.empty() ? s2[i] : s1[i]});
        return mis.empty() || (mis.size() == 2 && mis[0] == mis[1]);
    }
};