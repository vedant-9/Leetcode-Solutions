// https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts

class Solution {
public:
    int minimumOperations(vector<int>& a) {
        unordered_set<int> s(a.begin(), a.end());
        return s.size() - s.count(0);
    }
};