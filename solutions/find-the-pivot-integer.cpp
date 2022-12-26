// https://leetcode.com/problems/find-the-pivot-integer

class Solution {
public:
    int pivotInteger(int n) {
        int rsum = n*(n+1)/2, sum = 0;
        for(int i=1; i<=n; i++) {
            sum += i;
            if(sum == rsum) return i;
            rsum -= i;
        }
        return -1;
    }
};