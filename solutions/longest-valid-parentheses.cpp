// https://leetcode.com/problems/longest-valid-parentheses

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        
        stack<int> st;
        st.push(-1);
        
        int max_len = 0;
        for(int i=0;i<n;i++) {
            if(s[i]=='(') {
                st.push(i);
            } else {
                st.pop();
                if(st.empty()) {
                    st.push(i);
                } else {
                    max_len = max(max_len,i-st.top());
                }
            }
        }
        
        return max_len;
    }
};