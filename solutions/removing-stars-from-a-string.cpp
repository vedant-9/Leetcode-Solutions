// https://leetcode.com/problems/removing-stars-from-a-string

class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(auto ch:s) {
            if(ch!='*') st.push(ch);
            else st.pop();
        }
        string res = "";
        while(!st.empty()) res += st.top(), st.pop();
        reverse(res.begin(),res.end());
        return res;
    }
};