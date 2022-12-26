// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& A) 
    {
        int sum = 0,mx=INT_MIN;
        for(int i=0;i<A.size();i++)
        {
            sum += A[i];
            if(sum>mx)
                mx = sum;
            if(sum<0)
                sum = 0;
        }
        return mx;
    }
};