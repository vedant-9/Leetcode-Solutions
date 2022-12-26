// https://leetcode.com/problems/sum-of-prefix-scores-of-strings

class Solution {
public:
    class Trie {
    public:
        Trie() {}

        void insert(string word) {
            Trie* node = this;
            for (char ch : word) {
                ch -= 'a';
                node->cnt[ch]++;
                if (!node->next[ch]) { node->next[ch] = new Trie(); }
                node = node->next[ch];
            }
        }

        int get(string word) {
            Trie* node = this;
            int ans = 0;
            for (char ch : word) {
                ch -= 'a';
                if (!node->next[ch]) { return false; }
                ans += node->cnt[ch];
                node = node->next[ch];
            }
            return ans;
        }

    private:
        Trie* next[26] = {};
        int cnt[26] = {};
    };
    
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* node = new Trie();
        
        for(auto &w: words) {
            node->insert(w);   
        }
        
        vector<int> res;
        for(auto &w: words) {
            int ans = node->get(w);
            res.push_back(ans);
        }
        
        return res;
    }
};