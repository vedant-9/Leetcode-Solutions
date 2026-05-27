class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lowerVisInd(26, -1), upperVisInd(26, -1);
        int ind = 0;
        for(auto ch: word) {
            if(ch >= 'a' and ch <= 'z') lowerVisInd[ch-'a'] = ind;
            else {
                if(upperVisInd[ch - 'A'] == -1) upperVisInd[ch - 'A'] = ind;
            }
            ind++;
        }
        int cnt = 0;
        for(int i = 0; i < 26; i++) {
            if(lowerVisInd[i] != -1 and upperVisInd[i] != -1 and lowerVisInd[i] < upperVisInd[i]) cnt++;
        }
        return cnt;
    }
};
