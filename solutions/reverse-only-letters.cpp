// https://leetcode.com/problems/reverse-only-letters

class Solution {
public:
    string reverseOnlyLetters(string s) 
    {
        string letters = "";
        for(auto c:s)
        {
            if((c>='A' && c<='Z') || (c>='a' && c<='z'))
                letters += c;
        }
       
        string ans = "";
        int i = letters.length()-1;
        for(int j=0;j<s.length();j++)
        {
            char c = s[j];
            if(!((c>='A' && c<='Z') || (c>='a' && c<='z')))
                ans += c;
            else
                ans += letters[i--];
                
        }
        
        return ans;
    }
};