// https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles

class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& a) 
    {
        map<double,long long> m;
        for(auto x:a)
        {
            m[(x[0]*1.0/x[1])]++;
        }
        
        long long ans = 0;
        for(auto it:m)
        {
            // cout<<it.first<<" "<<it.second<<" ";
            ans += (it.second)*(it.second-1)/2;
        }
        return ans;
    }
};