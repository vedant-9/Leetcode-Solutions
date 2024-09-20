class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        // 1. Using Set to store each prefix
        // 2. Using Trie
        set<string> st;
        for(auto x: arr1) {
            string t = to_string(x), pre = "";
            for(auto ch: t) {
                pre += ch;
                st.insert(pre);
            }
        }
        
        int ans = 0;
        for(auto x: arr2) {
            string t = to_string(x), pre = "";
            for(auto ch: t) {
                pre += ch;
                if(st.find(pre) != st.end()) ans = max(ans, (int) pre.size());
            }
        }
        
        return ans;
    }
};
