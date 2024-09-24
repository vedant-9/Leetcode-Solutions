class Solution {
public:
    class TrieNode {
    public:
        unordered_map<char, TrieNode*> children;
        bool isEndOfWord;

        TrieNode() {
            isEndOfWord = false;
        }
    };
    class Trie {
    private:
        TrieNode* root;

    public:
        Trie() {
            root = new TrieNode();
        }

        // Insert a word into the trie
        void insert(const string &word) {
            TrieNode* node = root;
            for (char ch : word) {
                if (!node->children.count(ch)) {
                    node->children[ch] = new TrieNode();
                }
                node = node->children[ch];
            }
            node->isEndOfWord = true;
        }

        // Search for a word in the trie
        bool search(const string &word) {
            TrieNode* node = root;
            for (char ch : word) {
                if (!node->children.count(ch)) {
                    return false;
                }
                node = node->children[ch];
            }
            return true;
        }
    };

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        // 1. Using Set to store each prefix
        // 2. Using Trie
        Trie trie;
        for(auto x: arr1) {
            string t = to_string(x);
            trie.insert(t);
        }
        
        int ans = 0;
        for(auto x: arr2) {
            string t = to_string(x), pre = "";
            for(auto ch: t) {
                pre += ch;
                if(trie.search(pre)) ans = max(ans, (int) pre.size());
            }
        }
        
        return ans;
    }
};


