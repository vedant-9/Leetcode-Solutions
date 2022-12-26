// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii

class Solution {
public:
    int minMoves2(vector<int>& a) {
        int n = a.size ();
        sort (a.begin(), a.end());
        int mid = n/2, i = 0, count = 0;
        for (i = 0; i < n; i++)
            count += abs (a [i] - a [mid]);
        return count;
    }
};