// https://leetcode.com/problems/shifting-letters-ii

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        // line sweep technique
        int n = s.size();
        
        int line[50001] = {};
        for(auto &shift: shifts) {
            line[shift[0]] += shift[2]?1:-1;
            line[shift[1]+1] += shift[2]?-1:1; 
        }
        
        int val = 0;
        for(int i=0; i<n; i++) {
            val = (val+line[i])%26;
            s[i] = 'a' + ((s[i]-'a')+val+26)%26;
        }
        
        return s;
    }
};