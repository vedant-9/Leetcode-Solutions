// https://leetcode.com/problems/remove-palindromic-subsequences

class Solution {
public:
    int removePalindromeSub(string s) 
    {
        // either 0 or 1 or 2
        return 2 - (s == string(s.rbegin(), s.rend())) - s.empty();
    }
};