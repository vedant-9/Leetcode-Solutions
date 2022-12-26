// https://leetcode.com/problems/pascals-triangle-ii

class Solution {
public:
    vector<int> getRow(int r) 
    {
        if(r==0)
            return {1};
        
        vector<int> prev,cur;
        // prev.push_back(1);
        for(int i=0;i<r;i++)
        {
            cur.push_back(1);
            int p = 1;
            for(int j=1;j<prev.size();j++)
            {
                cur.push_back(p+prev[j]);
                p = prev[j];
            }
            cur.push_back(1);
            prev = cur;
            cur.clear();
        }
        return prev;
    }
};