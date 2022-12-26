// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

class Solution {
public:
    int strStr(string s, string p) 
    {
        return s.find(p);
    }
};