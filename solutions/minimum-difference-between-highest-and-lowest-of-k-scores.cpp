// https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores

class Solution {
public:
    int minimumDifference(vector<int>& a, int k) 
    {
        // if(a.size()==1)
        //     return a[0];
        sort(a.begin(),a.end());
        int mn = INT_MAX;
        for(int i=0;i<a.size()-k+1;i++)
            mn = min(mn,a[i+k-1]-a[i]);
        return mn;
    }
};