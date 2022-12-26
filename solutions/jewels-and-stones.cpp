// https://leetcode.com/problems/jewels-and-stones

class Solution {
public:
    int numJewelsInStones(string j, string s) 
    {
        int res = 0;
        unordered_set<char> set(j.begin(), j.end());
        for (char c : s)
            if (set.count(c)) res++;
        return res;
    }
};