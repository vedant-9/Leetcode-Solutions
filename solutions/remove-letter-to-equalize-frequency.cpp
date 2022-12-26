// https://leetcode.com/problems/remove-letter-to-equalize-frequency

class Solution {
public:
    bool equalFrequency(string word) {
        int cnt[26] = {0};
        for(auto &ch: word) {
            cnt[ch - 'a']++;
        }
        for(auto &ch: word) {
            cnt[ch - 'a']--;
            map<int, int> freq;
            for(auto &x: cnt) {
                if(x) freq[x]++;
            }
            if(freq.size() == 1) return 1;
            cnt[ch - 'a']++;
        }
        return 0;
    }
};