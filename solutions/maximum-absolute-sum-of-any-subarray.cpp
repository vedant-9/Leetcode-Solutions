// https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray

class Solution {
public:
    int maxAbsoluteSum(vector<int>& a) 
    {
        int n = a.size();
        
        int mx1 = INT_MIN, sum1 = 0;
        for(int i=0;i<n;i++)
        {
            sum1 += a[i];
            mx1 = max(mx1,sum1);
            if(sum1<0) sum1 = 0;
        }
        
        int mx2 = INT_MIN, sum2 = 0;
        for(int i=0;i<n;i++)
        {
            sum2 += -a[i];
            mx2 = max(mx2,sum2);
            if(sum2<0) sum2 = 0;
        }
        
        return max(mx1,mx2);
    }
};