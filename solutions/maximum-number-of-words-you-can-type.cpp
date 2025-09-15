class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
        int count = 0;
        
        stringstream ss(text);
        string word;
        
        while (ss >> word) {
            bool canType = true;
            for (char c : word) {
                if (broken.count(c)) {
                    canType = false;
                    break;
                }
            }
            if (canType) count++;
        }
        
        return count;
    }
};
