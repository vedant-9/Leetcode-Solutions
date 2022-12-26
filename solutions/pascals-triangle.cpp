// https://leetcode.com/problems/pascals-triangle

class Solution {
public:
    vector<vector<int>> generate(int n) 
    {
        vector<vector<int>> res;
        
        vector<int> prev,cur;
        cur.push_back(1);
        res.push_back(cur);
        prev = cur;
        
        for(int i=0;i<n-1;i++)
        {
            cur.clear();
            cur.push_back(1);
            for(int i=1;i<prev.size();i++)
            {
                cur.push_back(prev[i]+prev[i-1]);
            }
            cur.push_back(1);
            res.push_back(cur);
            prev = cur;
        }
        return res;
    }
};