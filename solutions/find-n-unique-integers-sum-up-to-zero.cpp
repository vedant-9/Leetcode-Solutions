// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero

class Solution {
public:
    vector<int> sumZero(int n) 
    {
        // will not work if n>1e5
        vector<int> a(n);
        for (int i = 1; i < n; i++) {
            a[i] = i;
            a[0] -= i;
        }
        return a;
    }
};