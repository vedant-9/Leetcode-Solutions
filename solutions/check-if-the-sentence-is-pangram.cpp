// https://leetcode.com/problems/check-if-the-sentence-is-pangram

class Solution {
public:
    bool checkIfPangram(string s) 
    {
        bool a[26] = {0};
        for(auto c:s)
            a[c-'a'] = 1;
        for(auto x:a)
            if(x==0)
                return false;
        return true;
    }
};