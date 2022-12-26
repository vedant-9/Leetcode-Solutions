// https://leetcode.com/problems/maximum-number-of-weeks-for-which-you-can-work

class Solution {
public:
    long long numberOfWeeks(vector<int>& a) 
    {
        int n = a.size();
        long long sum = 0;
        for(auto x:a) sum += x;
        
        long long mx = *max_element(a.begin(),a.end());
        
        if(mx<=sum-mx)
        {
            return sum;
        }
        return (min(mx,sum-mx)*2+1);
    }
};