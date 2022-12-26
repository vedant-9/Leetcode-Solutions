// https://leetcode.com/problems/best-sightseeing-pair

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& a) 
    {
        int res = 0, cur = 0;
        for (int x: a) 
        {
            res = max(res, cur + x);
            cur = max(cur, x) - 1;
        }
        return res;
    }
};