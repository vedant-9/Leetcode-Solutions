// https://leetcode.com/problems/find-all-anagrams-in-a-string

class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        vector<int> pv(26,0), sv(26,0), res;
        
        if(s.size() < p.size())
           return res;
        
        // hashmaps filling
        for(int i = 0; i < p.size(); ++i)
        {
            ++pv[p[i]-'a'];
            ++sv[s[i]-'a'];
        }
        
        // p size window
        if(pv == sv)
           res.push_back(0);

        //here window is moving from left to right across the string. 
        //window size is p.size(), so s.size()-p.size() moves are made 
        for(int i = p.size(); i < s.size(); ++i) 
        {
            ++sv[s[i]-'a'];
            --sv[s[i-p.size()]-'a'];
            
            if(pv == sv)  
               res.push_back(i-p.size()+1);
        }
        return res;
    }
};