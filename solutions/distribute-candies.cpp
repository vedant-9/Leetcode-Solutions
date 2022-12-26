// https://leetcode.com/problems/distribute-candies

class Solution {
public:
    int distributeCandies(vector<int>& a) 
    {
        set<int> s;
        for(auto x:a) s.insert(x);
        return ((s.size()>a.size()/2)?a.size()/2:s.size());
    }
};