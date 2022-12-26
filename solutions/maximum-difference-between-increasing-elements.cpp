// https://leetcode.com/problems/maximum-difference-between-increasing-elements

class Solution {
public:
    int maximumDifference(vector<int>& a) 
    {
        int n = a.size();
        int ans = INT_MIN;
        for(int i=0;i<n-1;i++)
        {
            int mx = INT_MIN;
            for(int j=i+1;j<n;j++)
            {
                mx = max(mx,a[j]);
            }
            if(a[i]<mx)
                ans = max(ans,mx-a[i]);
        }
        if(ans==INT_MIN)
            return -1;
        return ans;
    }
};