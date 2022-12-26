// https://leetcode.com/problems/minimum-distance-to-the-target-element

class Solution {
public:
    int getMinDistance(vector<int>& a, int tar, int st) 
    {
        int n = a.size();
        int mn = INT_MAX;
        int i = st;
        while(i<n && a[i]!=tar)
        {
            i++;
        }
        if(i!=n && a[i]==tar)
        {
            mn = i-st;
        }
        i = st-1;
        while(i>=0 && a[i]!=tar)
        {
            i--;
        }
        if(i!=-1 && a[i]==tar)
        {
            mn = min(mn,st-i);
        }
        return mn;
    }
};