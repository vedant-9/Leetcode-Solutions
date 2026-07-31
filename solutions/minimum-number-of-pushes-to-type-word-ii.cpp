class Solution {
public:
    int minimumPushes(string word) {
        int freq[26] = {};
        for (char c : word) freq[c - 'a']++;
        sort(freq, freq + 26, greater<int>());
        
        int pushes = 0;
        for (int i = 0; i < 26 && freq[i]; i++)
            pushes += freq[i] * (i / 8 + 1);
        return pushes;
    }
};
