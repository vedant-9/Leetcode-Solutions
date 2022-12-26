// https://leetcode.com/problems/count-words-obtained-after-adding-a-letter

class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<string> s;
        for (auto &w : startWords) {
            sort(begin(w), end(w));
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                int p = lower_bound(begin(w), end(w), ch) - begin(w);
                if (p == w.size() || w[p] != ch)
                    s.insert(w.substr(0, p) + ch + w.substr(p));
            }
        }
        int res = 0;
        for (auto &w : targetWords) {
            sort(begin(w), end(w));
            res += s.count(w);
        }
        return res;
    }
};