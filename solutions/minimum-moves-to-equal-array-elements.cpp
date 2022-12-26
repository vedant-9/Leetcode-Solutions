// https://leetcode.com/problems/minimum-moves-to-equal-array-elements

class Solution {
public:
    int minMoves(vector<int>& a) 
    {
        int sum = a[0], mn = a[0],n = a.size();
        for(int i=1;i<n;i++)
            sum += a[i],mn = min(mn,a[i]);
        return sum-n*mn;
    }
};