// https://leetcode.com/problems/combination-sum

class Solution {
public:
    
    vector<vector<int>> ans;
    vector<int> a;
    void rec(int tar,vector<int> t,int idx)
    {
        if(tar==0)
        {
            ans.push_back(t);  
            return;
        }
        for(int i=idx;i<a.size() && tar>=a[i];i++)
        {
            t.push_back(a[i]);
            rec(tar-a[i],t,i);
            t.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& A, int tar) 
    {
        a = A;
        vector<int> t;
        sort(a.begin(),a.end());
        rec(tar,t,0);
        return ans;
    }
};