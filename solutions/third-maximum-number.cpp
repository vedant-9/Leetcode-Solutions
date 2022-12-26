// https://leetcode.com/problems/third-maximum-number

class Solution {
public:
    int thirdMax(vector<int>& a) 
    {
        set<int,greater<int>> s;
        for(auto x:a)
            s.insert(x);
        
        if(s.size()<3)
            return *s.begin();
        auto it = s.begin();
        it++;
        it++;
        return *it;
    }
};