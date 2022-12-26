// https://leetcode.com/problems/reverse-words-in-a-string

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int i = 0, n = s.size();
        while(i<n and s[i]==' ') i++;
        while(i<n) {
            if(s[i] == ' ') {
                i++; continue;
            }
            string w = "";
            while(i<n and s[i] != ' ') w += s[i], i++; 
            words.push_back(w);
        }
        string res = "";
        for(int i = words.size()-1; i>=0; i--) {
            res += words[i];
            if(i) res += " ";
        }
        return res;
    }
};