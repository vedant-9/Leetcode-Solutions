// https://leetcode.com/problems/word-ladder

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int wordSize = beginWord.size();
        
        unordered_set<string> wordSet;
        for(auto &word: wordList) {
            wordSet.insert(word);
        }
        
        queue<string> q;
        q.push(beginWord);
        
        int ladder = 1;
        
        while(!q.empty()) {
            int qsize = q.size();
            
            while(qsize--) {
                auto curWord = q.front(); q.pop();
                
                if(curWord == endWord) {
                    return ladder;
                }

                for(int i = 0; i < wordSize; i++) {
                    for(char ch = 'a'; ch <= 'z'; ch++) {
                        if(curWord[i] == ch) continue;
                        
                        string nextWord = curWord;
                        nextWord[i] = ch;
                        
                        if(wordSet.count(nextWord)) {
                            q.push(nextWord);
                            wordSet.erase(nextWord);
                        }
                    }
                }
            }
            
            ladder++;
        }
        
        return 0;
    }
};