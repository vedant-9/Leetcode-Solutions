// https://leetcode.com/problems/smallest-value-after-replacing-with-sum-of-prime-factors

class Solution {
public:
    int smallestValue(int n) {
        while(1) {
            int sum = 0, x = n, d = 2;
            while(x>1) {
                while(x%d == 0) x/=d, sum += d;
                d++;
            }
            if(sum == n) break;
            n = sum;
        }
        return n;
    }
};