// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii

class Solution {
public:
    int minSteps(string s, string t) {
        int cnt[26] = {0};
        for(auto c:s) cnt[c-'a']++;
        int ans = 0;
        for(auto c:t) {
            if(cnt[c-'a']>0) cnt[c-'a']--;
            else ans++;
        }
        for(auto x:cnt) ans+=x;
        return ans;
    }
};