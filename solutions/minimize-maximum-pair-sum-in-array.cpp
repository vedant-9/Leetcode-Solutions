// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array

class Solution {
public:
    int minPairSum(vector<int>& a) 
    {
        int n = a.size();
        sort(a.begin(),a.end());
        int mx = a[0]+a[n-1];
        for(int i=1;i<n/2;i++)
        {
            int t = a[i]+a[n-i-1];
            if(t>mx)
                mx = t;
        }
        return mx;
    }
};