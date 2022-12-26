// https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences

class Solution {
public:
    bool areOccurrencesEqual(string s) 
    {
        map<int,int> a;
        
        for(auto c:s)
            a[c]++;
        
        int v = -1;
        for(auto it:a)
        {
            int x = it.second;
            if(v==-1)
                v = x;
            if(v!=-1 && v!=x)
                return 0;
        }
        return 1;
    }
};