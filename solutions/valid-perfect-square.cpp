// https://leetcode.com/problems/valid-perfect-square

class Solution {
public:
    bool isPerfectSquare(int num) 
    {
        long long int y = num,mul;
        if(y == 0) return 0;
        if(y == 1) return 1;
        int lo = 0, hi = y, mid;
        int t = 50;
        while(t--) {
            mid = lo + (hi-lo)/2;
            mul = (long long int)mid*mid;
            if(y == mul) 
                return mid;
            if(mul > y)
                hi = mid;
            else
                lo = mid;
        }
        bool flag = false;
        if(y == mul)
            flag = true;
        return flag;
    }
};