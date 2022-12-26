// https://leetcode.com/problems/palindrome-pairs

class Solution {
public:
    class TrieNode {
    public:
        TrieNode* next[26] = {};
        int endIndex = -1;
        vector<int> indices;
        
        TrieNode() {}

        void insert(string word, int idx) {
            TrieNode* node = this;
            // add reverse word into trie
            for(int i=word.size()-1; i>=0; i--) {
                // check if prefix of word forms palindrome
                if(isPalindrome(word, 0, i)) {
                    node->indices.push_back(idx);
                }
                
                int c = word[i]-'a';
                if(!node->next[c]) 
                    node->next[c] = new TrieNode();
                
                node = node->next[c];
            }
            node->endIndex = idx;
            // Empty prefix is also palindrome
            node->indices.push_back(idx);
        }
        
        bool isPalindrome(string &word, int i, int j) {
            while(i<j and word[i]==word[j]) i++,j--;
            return i>=j;
        }
    };
        
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        
        TrieNode* root = new TrieNode();
        
        for(int i=0; i<n; i++) 
            root->insert(words[i], i);
        
        vector<vector<int>> ans;
        for(int i=0; i<n; i++) {
            TrieNode* node = root;
            string word = words[i];

            for(int j=0; j<word.size() and node; j++) {
                if(node->endIndex != -1 and node->endIndex != i and node->isPalindrome(word, j, word.size()-1)) 
                    ans.push_back({i, node->endIndex});
                node = node->next[word[j]-'a'];
            }
            
            if(!node) continue;
            
            for(auto x: node->indices) {
                if(i != x) 
                    ans.push_back({i, x});
            }
        }
        
        return ans;
    }
};