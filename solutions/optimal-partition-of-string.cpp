// https://leetcode.com/problems/optimal-partition-of-string

class Solution {
public:
    int partitionString(string s) {
        set<char> st;
        int ans = 0;
        for(auto ch: s) {
            if(st.find(ch) != st.end()) {
                st.clear(); ans++;
            }
            st.insert(ch);
        }
        if(!st.empty()) ans++;
        return ans;
    }
};