// https://leetcode.com/problems/number-complement

class Solution {
public:
    int findComplement(int n) 
    {
        unsigned i = log2(n)+1;
        return n ^ ((unsigned)(1<<i)-1);
    }
};