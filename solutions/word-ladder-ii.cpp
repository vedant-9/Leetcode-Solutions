// https://leetcode.com/problems/word-ladder-ii

class Solution {
public:
    void dfs(int curLevel, vector<string> &curSequence, vector<vector<string>> &sequences, map<int, vector<string>> &levelWords) {
        
        if(curLevel == 0) {
            sequences.push_back(curSequence);
            return;
        }
        
        string curWord = curSequence.back();
        
        for(auto &prevWord: levelWords[curLevel-1]) {
            
            int charDiffCnt = 0;
            
            for(int i = 0; i < prevWord.size(); i++) {
                if(prevWord[i] != curWord[i]) 
                    charDiffCnt++;
            }
            
            if(charDiffCnt == 1) {
                curSequence.push_back(prevWord);
                dfs(curLevel-1, curSequence, sequences, levelWords);
                curSequence.pop_back();   
            }
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> sequences;
        
        int wordSize = beginWord.size();
        
        unordered_set<string> wordSet;
        for(auto &word: wordList) {
            wordSet.insert(word);
        }
        
        map<int, vector<string>> levelWords;
        
        queue<string> q;
        q.push(beginWord);
        
        bool foundShortestLadder = false;
        int level = 1;
        
        levelWords[0].push_back(beginWord);
        wordSet.erase(beginWord);
        
        while(!q.empty()) {
            int qsize = q.size();
            
            while(qsize--) {
                auto curWord = q.front(); q.pop();
                
                if(curWord == endWord) {
                    foundShortestLadder = true;
                    continue;
                }

                for(int i = 0; i < wordSize; i++) {
                    for(char ch = 'a'; ch <= 'z'; ch++) {
                        if(curWord[i] == ch) continue;
                        
                        string nextWord = curWord;
                        nextWord[i] = ch;
                        
                        if(wordSet.count(nextWord)) {
                            q.push(nextWord);
                            levelWords[level].push_back(nextWord);
                            wordSet.erase(nextWord);
                        }
                    }
                }
            }
            
            if(foundShortestLadder) 
                break;
            
            level++;
        }
        
        // for(auto it: levelWords) {
        //     cout<<it.first<<"->";
        //     for(auto x: it.second) {
        //         cout<<x<<" ";
        //     }
        //     cout<<endl;
        // }
        
        if(!foundShortestLadder)
            return sequences;
        
        vector<string> curSequence;
        curSequence.push_back(endWord);
        
        dfs(level-1, curSequence, sequences, levelWords);
        
        for(auto &seq: sequences) {
            reverse(seq.begin(), seq.end());
        }
        
        return sequences;
    }
};