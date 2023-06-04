class Solution {
public:
    int minimizedStringLength(string s) {
        vector<int> cnt(26, 0);
        for(auto ch: s) cnt[ch-'a']++;
        int ans = 0;
        for(auto x: cnt) ans += (x/3+x%3!=0);
        return ans;
    }
};
