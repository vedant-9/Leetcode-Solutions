// https://leetcode.com/problems/subsets

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& A) 
    {
        int n = A.size();
        vector<vector<int>> ans;
        for(int i=0;i<pow(2,n);i++)
        {
            vector<int> T;
            for(int j=0;j<n;j++)
            {
                if(i & (1<<j))
                    T.push_back(A[j]);
            }
            ans.push_back(T);
        }
        return ans;
    }
};