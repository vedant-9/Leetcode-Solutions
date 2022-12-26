// https://leetcode.com/problems/increasing-triplet-subsequence

class Solution {
public:
    bool increasingTriplet(vector<int>& a) 
    {
        int n = a.size();
        int premin[n], sufmax[n];
        
        premin[0] = a[0];
        for(int i=1;i<n;i++)
            premin[i] = min(premin[i-1],a[i]);
        
        sufmax[n-1] = a[n-1];
        for(int i=n-2;i>=0;i--)
            sufmax[i] = max(sufmax[i+1],a[i]);
        
        for(int i=1;i<n-1;i++)
        {
            if(premin[i-1]<a[i] and a[i]<sufmax[i+1])
                return 1;
        }
        return 0;
    }
};