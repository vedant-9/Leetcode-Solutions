// https://leetcode.com/problems/concatenated-words

class Solution {
public:
    class TrieNode {
    public:
        TrieNode* next[26] = {};
        bool isend = false;
        
        TrieNode() {}

        void insert(string word) {
            TrieNode* node = this;
            for (auto ch: word) {
                ch -= 'a';
                if (!node->next[ch]) 
                    node->next[ch] = new TrieNode(); 
                node = node->next[ch];
            }
            node->isend = true;
        }
        
        bool dfs(TrieNode* node, int idx, int cnt, string &word) {
            if(!node) return 0;
            
            // Check if there is cut made or not
            if(idx == word.size()) {
                if(node->isend and cnt>=1) return 1;
                return 0;
            }
            
            // found some base word so add cut and again call dfs for remaining 
            if(node->isend and dfs(this, idx, cnt+1, word)) 
                return 1;
            
            return dfs(node->next[word[idx]-'a'], idx+1, cnt, word);
        }
        
    };
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        // sort by size for getting base words first
        sort(words.begin(), words.end(), [](const string& w1, const string& w2) {
            return w1.size() < w2.size();
        });
        
        TrieNode* root = new TrieNode();
        
        vector<string> concatWords;
        
        // Only add base words into trie
        for(auto &word: words) {
            if(word.empty()) continue;
            
            if(root->dfs(root, 0, 0, word)) 
                concatWords.push_back(word);
            else
                root->insert(word);
        }
        
        return concatWords;
    }
};