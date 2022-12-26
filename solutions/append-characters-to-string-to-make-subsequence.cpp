// https://leetcode.com/problems/append-characters-to-string-to-make-subsequence

class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.size(), m = t.size();
        int j = 0;
        for(int i=0; i<n; i++) {
            if(j<m and s[i] == t[j]) {
                j++; 
            }
        }
        return m-j;
    }
};