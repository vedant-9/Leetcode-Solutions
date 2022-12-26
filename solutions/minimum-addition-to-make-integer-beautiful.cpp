// https://leetcode.com/problems/minimum-addition-to-make-integer-beautiful

class Solution {
public:
    int digSum(long long n) {
        int sum = 0;
        while(n) {
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
    long long makeIntegerBeautiful(long long n, int target) {
        long long m = n, base = 1;
        while(digSum(n) > target) {
            n = n/10+1;
            base *= 10;
        }
        return n*base-m;
    }
};