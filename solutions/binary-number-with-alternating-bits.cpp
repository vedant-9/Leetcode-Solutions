// https://leetcode.com/problems/binary-number-with-alternating-bits

class Solution {
public:
    bool hasAlternatingBits(int n) 
    {
        int f = n%2;
        while(n)
        {
            if(n%2!=f)
                return false;
            f = !f;
            n>>=1;
        }
        return true;
    }
};