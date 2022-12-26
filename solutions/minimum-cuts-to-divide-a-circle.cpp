// https://leetcode.com/problems/minimum-cuts-to-divide-a-circle

class Solution {
public:
    int numberOfCuts(int n) {
        if(n!=1 and n&1) return n;
        return n/2;
    }
};