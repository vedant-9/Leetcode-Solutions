// https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case

class Solution {
public:
    string greatestLetter(string s) {
        set<char> st;
        for(auto x:s) st.insert(x);
        for(int i=25;i>=0;i--) {
            if(st.find('a'+i)!=st.end() and st.find('A'+i)!=st.end()) 
                return string(1,'A'+i);
        }
        return "";
    }
};