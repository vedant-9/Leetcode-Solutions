class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        int i = 0, n = word.size();
        while(i < n) {
            int j = i;
            while(i < n and word[j] == word[i]) i++;
            int cnt = i - j;
            while(cnt > 9) {
                ans += to_string(9) + word[j];
                cnt -= 9;
            }
            ans += to_string(cnt) + word[j];
        }
        return ans;
    }
};
