// https://leetcode.com/problems/check-if-number-has-equal-digit-count-and-digit-value

class Solution {
public:
    bool digitCount(string s) {
        int cnt[10]={0};
        for(auto ch:s) cnt[ch-'0']++;
        for(int i=0;i<s.length();i++) if(cnt[i]!=(s[i]-'0')) return 0;
        return 1;
    }
};