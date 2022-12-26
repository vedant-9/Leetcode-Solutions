// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> freq;
        for(auto word: words) {
            freq[word]++;
        }
        
        int length = 0;
        bool middleTaken = false;
        
        for(auto &word: words) {
            string rword = word;
            reverse(rword.begin(), rword.end());
            
            if(word != rword and freq[word] > 0 and freq[rword] > 0) 
                length += 4, freq[word]--, freq[rword]--;
            else if(word == rword and freq[word] > 1) 
                length += 4, freq[word] -= 2;
            else if(word == rword and freq[word] > 0 and !middleTaken) 
                length += 2, freq[word]--, middleTaken = true;
        }
        
        return length;
    }
};