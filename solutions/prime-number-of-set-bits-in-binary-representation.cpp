// https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation

class Solution {
public:
    int countPrimeSetBits(int L, int R) 
    {
        // 665772 contains set bits at prime positions as 2nd,3rd,..upto 31th
        int count = 0;
        while (L <= R)
            count += 665772 >> __builtin_popcount(L++) & 1;
        return count;
    }
};