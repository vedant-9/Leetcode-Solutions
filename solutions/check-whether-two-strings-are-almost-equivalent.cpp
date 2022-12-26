// https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent

class Solution {
public:
    bool checkAlmostEquivalent(string s1, string s2) {
        int c1[26]={0},c2[26]={0};
        for(auto c:s1) c1[c-'a']++;
        for(auto c:s2) c2[c-'a']++;
        for(int i=0;i<26;i++) {
            if(abs(c1[i]-c2[i])>3) return false;
        }
        return true;
    }
};