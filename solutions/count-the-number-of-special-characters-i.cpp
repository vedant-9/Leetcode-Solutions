class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lowerVis(26, 0), upperVis(26, 0);
        for(auto ch: word) {
            if(ch >= 'a' and ch <= 'z') lowerVis[ch-'a'] = 1;
            else upperVis[ch - 'A'] = 1;
        }
        int cnt = 0;
        for(int i = 0; i < 26; i++) {
            if(lowerVis[i] and upperVis[i]) cnt++;
        }
        return cnt;
    }
};
