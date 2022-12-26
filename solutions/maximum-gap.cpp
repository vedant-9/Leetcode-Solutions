// https://leetcode.com/problems/maximum-gap

class Solution {
public:
    int maximumGap(vector<int>& a) {
        sort(a.begin(),a.end());
        int n = a.size();
        if(n==1)
            return 0;
        int mx = a[1]-a[0];
        for(int i=2;i<n;i++)
        {
            mx = max(mx,a[i]-a[i-1]);
        }
        return mx;
    }
};