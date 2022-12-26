// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) 
    {
        if(a.size()<=1)
            return a;
        
        vector<vector<int>> v;
        
        sort(a.begin(),a.end());
        v.push_back(a[0]);
        
        int j=0;
        for(int i=1;i<a.size();i++)
        {
            if(a[i][0]<=v[j][1])
                v[j][1]=max(a[i][1],v[j][1]);
            else
            {
                v.push_back(a[i]);
                j++;
            }
        }
        return v;
    }
};