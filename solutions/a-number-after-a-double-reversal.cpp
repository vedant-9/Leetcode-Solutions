// https://leetcode.com/problems/a-number-after-a-double-reversal

class Solution {
public:
    bool isSameAfterReversals(int num) {
        int rn = 0, n = num;
        while(n) {
            rn=rn*10+n%10;
            n/=10;
        }
        int rrn = 0;
        while(rn) {
            rrn=rrn*10+rn%10;
            rn/=10;
        }
        return (rrn==num);
    }   
};