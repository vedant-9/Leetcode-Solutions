class Solution {
public:
    int minOperations(int n) {
        return __builtin_popcount(n ^ (n*3));
    }
};
