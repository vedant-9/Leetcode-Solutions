// https://leetcode.com/problems/rearrange-characters-to-make-target-string

class Solution {
public:
    int rearrangeCharacters(string s, string t) {
        int cnt[26]={0},req[26]={0};
        for(auto ch:s) cnt[ch-'a']++;
        for(auto ch:t) req[ch-'a']++;
        int mn = INT_MAX;
        for(int i=0;i<26;i++) {
            if(req[i]==0) continue;
            mn = min(mn,cnt[i]/req[i]);
        }
        if(mn==INT_MAX) mn=0;
        return mn;
    }
};