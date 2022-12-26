// https://leetcode.com/problems/count-items-matching-a-rule

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string key, string val) 
    {
        int idx = key == "type" ? 0 : key == "color" ? 1 : 2;
        return count_if(begin(items), end(items), [&](const auto &i) { return i[idx] == val; });
    }
};