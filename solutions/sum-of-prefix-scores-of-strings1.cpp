class Solution {
public:
    class Trie {
        Trie* next[26] = {};
        int cnt;
        
    public:
        Trie() {
            this->cnt = 0;
        }

        void insert(string word) {
            auto node = this;
            for (char ch : word) {
                ch -= 'a';
                if (!node->next[ch]) { node->next[ch] = new Trie(); }
                node->next[ch]->cnt++;
                node = node->next[ch];
            }
        }

        int getPrefixCount(string word) {
            Trie* node = this;
            int ans = 0;
            for (char ch : word) {
                ch -= 'a';
                ans += node->next[ch]->cnt;
                node = node->next[ch];
            }
            return ans;
        }
    };
    
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* node = new Trie();
        
        for(auto &w: words) {
            node->insert(w);   
        }
        
        vector<int> res;
        for(auto &w: words) {
            int ans = node->getPrefixCount(w);
            res.push_back(ans);
        }
        
        return res;
    }
};
