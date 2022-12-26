// https://leetcode.com/problems/repeated-dna-sequences

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        int n = s.size();
        
        map<string,int> m;
        for(int i=0;i<n-10+1;i++)
        {
            m[s.substr(i,10)]++;
        }
        
        vector<string> res;
        for(auto it:m)
        {
            if(it.second>1)
            {
                res.push_back(it.first);
            }
        }
        return res;
    }
};