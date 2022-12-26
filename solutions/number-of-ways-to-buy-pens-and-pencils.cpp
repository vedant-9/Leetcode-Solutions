// https://leetcode.com/problems/number-of-ways-to-buy-pens-and-pencils

class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans = 0;
        for(int i=0;i<=total/cost1;i++) {
            long long rem = total-i*cost1;
            long long t = (rem/cost2+1);
            ans += t;
        }
        return ans;
    }
};