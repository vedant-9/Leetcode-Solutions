// https://leetcode.com/problems/break-a-palindrome

class Solution {
public:
    string breakPalindrome(string s) 
    {
        int n = s.length();
        
        int i = 0;
        while(i<n/2 and s[i]=='a')
            i++;
        if(i==n/2)
            s[n-1] = 'b';
        else
            s[i] = 'a';
        return n<2?"":s;
    }
};