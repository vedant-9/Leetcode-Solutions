// https://leetcode.com/problems/count-the-number-of-consistent-strings

class Solution {
public:
    int countConsistentStrings(string s, vector<string>& words) 
    {
        int res = words.size();
        bool alpha[26] = {};
        
        // populating alpha
        for (char c: s) alpha[c - 'a'] = true;
        
        // parsing all the words to see if each character is in alpha
        for (string word: words) 
        {
            // in case we find an unallowed character, we decrease res and break
            for (char c: word) 
                if (!alpha[c - 'a']) 
                {
                    res--;
                    break;
                }
        }
        return res;
    }
};