// https://leetcode.com/problems/first-unique-character-in-a-string

class Solution {
public:
    int firstUniqChar(string s) 
    {
        int list[256] = {0};
        for(auto i: s)
            list[i]++;
        for(int i=0; i<s.length();i++)
            if(list[s[i]]==1) return i;
        return -1;
    }
};