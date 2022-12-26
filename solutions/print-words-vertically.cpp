// https://leetcode.com/problems/print-words-vertically

class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> res;
        if (s.size() == 0) return res;
        res.push_back({});
        int col = 0, row = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                col++;
                row = 0;
                continue;
            }
            if (row >= res.size()) {
                res.push_back({});
            }
            if (res[row].size() < col) {
                res[row].append(string(col - res[row].size(), ' '));
            }
            res[row++].push_back(s[i]);
        }
        return res;
    }
};