// https://leetcode.com/problems/teemo-attacking

class Solution {
public:
    int findPoisonedDuration(vector<int>& ts, int duration) 
    {
        int tp = 0, pe = 0;
        for(int i=0; i<ts.size(); ++i)
        {
            tp += duration - (ts[i] < pe) *(pe - ts[i]);
            pe = ts[i] + duration;
        }
        return tp;
    }
};