// https://leetcode.com/problems/bitwise-ors-of-subarrays

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& a) 
    {
        unordered_set<int> res, cur, cur2;
        for (int i: a) 
        {
            cur2 = {i};
            for (int j: cur) cur2.insert(i|j);
            for (int j: cur = cur2) res.insert(j);
        }
        return res.size();
    }
};