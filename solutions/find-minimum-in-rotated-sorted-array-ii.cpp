// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii

class Solution {
public:
    int findMin(vector<int>& a) {
        // TC - O(n) and SC - O(1)
        int mn = a[0];
        for(auto x:a) mn=min(mn,x);
        return mn;
    }
};