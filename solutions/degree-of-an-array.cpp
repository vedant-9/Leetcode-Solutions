// https://leetcode.com/problems/degree-of-an-array

class Solution {
public:
    int findShortestSubArray(vector<int>& a) 
    {
        map<int,int> m;
        int n = a.size();
        for(auto x:a)
            m[x]++;
        int mcx = 0;
        for(auto it:m)
        {
            if(it.second>mcx)
            {
                mcx = it.second;
            }
        }
        vector<int> l;
        for(auto it:m)
        {
            if(it.second==mcx)
            {
                l.push_back(it.first);
            }
        }
        int mn = INT_MAX;
        for(auto x:l)
        {
            int i,j;
            i = 0;
            while(i<n && a[i]!=x)
                i++;
            j = n-1;
            while(j>=0 && a[j]!=x)
                j--;
            mn = min(mn,j-i+1);
        }
        return mn;
    }
};