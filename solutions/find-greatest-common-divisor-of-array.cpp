// https://leetcode.com/problems/find-greatest-common-divisor-of-array

class Solution {
public:
    int findGCD(vector<int>& a) 
    {
        int mn = INT_MAX, mx = INT_MIN;
        for(auto x:a)
        {
            if(x<mn)
                mn = x;
            if(x>mx)
                mx = x;
        }
        return __gcd(mn,mx);
    }
};