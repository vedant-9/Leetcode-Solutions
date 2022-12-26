// https://leetcode.com/problems/count-vowel-substrings-of-a-string

class Solution {
public:
    int countVowelSubstrings(string w) {
        int j = 0, k = 0, vow = 0, cnt = 0;
        unordered_map<char, int> m {{'a', 0}, {'e', 0}, {'i', 0}, {'o', 0}, {'u', 0}};
        for (int i = 0; i < w.size(); ++i) {
            if (m.count(w[i])) {
                if (++m[w[i]] == 1)
                    ++vow;
                while (vow == 5)
                    vow -= --m[w[k++]] == 0;
                cnt += (k - j);
            }
            else {
                m['a'] = m['e'] = m['i'] = m['o'] = m['u'] = vow = 0;
                j = k = i + 1;
            }
        }
        return cnt;
    }
};