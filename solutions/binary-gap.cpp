// https://leetcode.com/problems/binary-gap

class Solution {
public:
    int binaryGap(int n) 
    {
        int res = 0;
        for (int d = -32; n; n /= 2, d++)
            if (n&1) res = max(res, d), d = 0;
        return res;
    }
};