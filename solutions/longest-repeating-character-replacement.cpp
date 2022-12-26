// https://leetcode.com/problems/longest-repeating-character-replacement

class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0;
        int cnt[26] = {0};
        while (j < s.size()) {
            cnt[s[j++]-'A']++;
            if (j-i - *max_element(cnt, cnt+26) > k)
                cnt[s[i++]-'A']--;
        }
        return j - i;
    }
};