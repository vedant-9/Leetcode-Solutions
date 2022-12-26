// https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered

class Solution {
public:
    bool isCovered(vector<vector<int>>& v, int left, int right) 
    {
        for(int i=left;i<=right;i++)
        {
            int f = 0;
            for(auto x:v)
            {
                if(x[0]<=i && i<=x[1])
                {
                    f=1;
                    break;
                }
            }
            if(f==0)
                return false;
        }
        return true;
    }
};