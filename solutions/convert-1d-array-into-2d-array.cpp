// https://leetcode.com/problems/convert-1d-array-into-2d-array

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& a, int m, int n) 
    {
        if(m*n!=a.size())
            return {};
        vector<vector<int>> ans;
        vector<int> t;
        for(int i=0;i<a.size();i++)
        {
            if(i!=0 and i%n==0)
                ans.push_back(t),t.clear();
            t.push_back(a[i]);
        }
        ans.push_back(t);
        return ans;
    }
};