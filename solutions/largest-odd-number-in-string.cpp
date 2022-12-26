// https://leetcode.com/problems/largest-odd-number-in-string

class Solution {
public:
    string largestOddNumber(string s) {
        int n = s.length();
        int i = n-1;
        while(i>=0 && (s[i]-'0')%2==0)
            i--;
        return s.substr(0,i+1);
    }
};