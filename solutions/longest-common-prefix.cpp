class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // TC - O(n)
        // SC - O(1)
        string res = "";
        for (int i = 0; i < strs[0].size(); i++) {
            char ch = strs[0][i];
            for (auto s : strs) {
                if (i >= s.size() or s[i] != ch)
                    return res;
            }
            res += ch;
        }
        return res;
    }
};
