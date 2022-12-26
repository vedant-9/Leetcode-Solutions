// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        if (n < k) return false;
        unordered_set<string> st;
        for (int i = 0; i < n - k + 1; i++) {
            st.insert(s.substr(i, k));
        }
        return st.size() == pow(2, k);
    }
};