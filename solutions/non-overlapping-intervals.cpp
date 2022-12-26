// https://leetcode.com/problems/non-overlapping-intervals

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& a) 
    {
        auto comp = [](const vector<int>&i1, const vector<int>& i2){ return i1[0] < i2[0]; };
        sort(a.begin(), a.end(), comp);
        int res = 0, pre = 0;
        for (int i = 1; i < a.size(); i++) 
        {
            if (a[i][0] < a[pre][1]) 
            {
                res++;
                if (a[i][1] < a[pre][1]) 
                    pre = i;
            }
            else 
                pre = i;
        }
        return res;
    }
};