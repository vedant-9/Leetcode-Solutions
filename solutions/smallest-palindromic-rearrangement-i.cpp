class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        for (char ch : s) freq[ch - 'a']++;

        string half;
        char midChar = 0;
        for (int i = 0; i < 26; i++) {
            half += string(freq[i] / 2, char('a' + i));
            if (freq[i] % 2 == 1) midChar = 'a' + i;
        }

        string t(half.rbegin(), half.rend());
        return midChar ? half + midChar + t : half + t;
    }
};
