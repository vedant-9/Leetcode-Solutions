// https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing

class Solution {
public:
    int minOperations(vector<int>& a) 
    {
        int ans = 0, n = a.size();
        for(int i=1;i<n;i++)
        {
            if(a[i]<=a[i-1])
            {
                ans += a[i-1]-a[i]+1;
                a[i] = a[i-1]+1;
            }
        }
        return ans;
    }
};