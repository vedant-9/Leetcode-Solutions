// https://leetcode.com/problems/spiral-matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& A) 
    {
        int rb=0,cb=0,re=A.size()-1,ce=A[0].size()-1;
        vector<int> ans;
        while(rb<=re && cb<=ce)
        {
            for(int i=cb;i<=ce;i++)
            {
                ans.push_back(A[rb][i]);
            }
            rb++;
            if(rb>re)
                break;
            for(int i=rb;i<=re;i++)
            {
                ans.push_back(A[i][ce]);
            }
            ce--;
            if(ce<cb)
                break;
            for(int i=ce;i>=cb;i--)
            {
                ans.push_back(A[re][i]);
            }
            re--;
            if(rb>re)
                break;
            for(int i=re;i>=rb;i--)
            {
                ans.push_back(A[i][cb]);
            }
            cb++;
        }
        return ans;
    }
};