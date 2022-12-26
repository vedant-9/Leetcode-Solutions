// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& a) 
    {
        map<int,int> m;
        for(auto x:a)
            m[x]++;
        
        int p = 0;
        for(auto &it:m)
        {
            int l = it.second;
            it.second = p;
            p += l;
        }
        
        vector<int> ans;
        for(auto x:a)
            ans.push_back(m[x]);
        
        return ans;
    }
    
};