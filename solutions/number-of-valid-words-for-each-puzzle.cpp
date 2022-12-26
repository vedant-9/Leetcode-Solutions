// https://leetcode.com/problems/number-of-valid-words-for-each-puzzle

// We need two conditions:
// The word should contain the first letter of the puzzle - we check that with submask & first.
// The hashmap saves how many words match this submask, so we just add mask_freq[submask]. if it's not in the map it will add zero.
class Solution {
public:
    int maskWord(string word) {
        int mask = 0;
        for (auto c : word) mask |= (1 << c-'a');
        return mask;
    }
    
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> mask_freq;
        for (auto word : words) mask_freq[(maskWord(word))]++;
        
        vector<int> res;
        
        for (auto p : puzzles) {
            int mask = maskWord(p), submask = mask, first = (1 << p[0]-'a'), curr = 0;
            
            while (submask) {
                if (submask & first) curr += mask_freq[submask];
                
                submask = (submask-1) & mask;
            }
            
            res.push_back(curr);
        }
        return res;
    }
};