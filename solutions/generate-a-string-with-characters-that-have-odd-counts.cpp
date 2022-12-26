// https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts

class Solution {
public:
    string generateTheString(int n) 
    {
        if(n%2==0)
            return string(n-1,'a')+'b';
        return string(n,'a');
    }
};