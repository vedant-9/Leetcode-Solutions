// https://leetcode.com/problems/max-consecutive-ones

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& a) 
    {
        int c = 0,mc=0;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]==1)
                c++;
            else
                c=0;
            mc = max(mc,c);
        }
        return mc;
    }
};