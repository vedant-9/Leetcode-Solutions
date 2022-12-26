// https://leetcode.com/problems/percentage-of-letter-in-string

class Solution {
public:
    int percentageLetter(string s, char l) {
        int c=0;
        for(auto x:s) {
            if(x==l) c++;
        }
        int n = s.length();
        return 100*c/n;
    }
};