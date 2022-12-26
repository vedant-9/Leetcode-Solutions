// https://leetcode.com/problems/is-subsequence

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0;
        for(int i=0;i<t.length();i++) {
            if(j==s.length())
                return true;
            if(s[j]==t[i])
                j++;
        }
        if(j==s.length())
            return true;
        return false;
    }
};