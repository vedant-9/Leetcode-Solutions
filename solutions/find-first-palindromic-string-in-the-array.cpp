// https://leetcode.com/problems/find-first-palindromic-string-in-the-array

class Solution {
public:
    string firstPalindrome(vector<string>& a) {
        for(auto s:a) {
            string t=s; reverse(t.begin(),t.end());
            if(s==t) return s;
        }
        return "";
    }
};