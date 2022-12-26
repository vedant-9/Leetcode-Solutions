// https://leetcode.com/problems/number-of-good-pairs

class Solution {
public:
    int numIdenticalPairs(vector<int>& a)
    {
        int res = 0;
        unordered_map<int, int> count;
        for (int x: a) 
        {
            res += count[x]++;
        }
        return res;
    }
};