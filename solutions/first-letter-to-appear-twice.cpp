// https://leetcode.com/problems/first-letter-to-appear-twice

class Solution {
public:
    char repeatedCharacter(string s) {
        set<char> st;
        for(auto ch:s) {
            if(st.find(ch)!=st.end())
                return ch;
            st.insert(ch);
        }
        return '/';
    }
};