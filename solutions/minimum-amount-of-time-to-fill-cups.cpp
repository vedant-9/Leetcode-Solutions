// https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups

class Solution {
public:
    int fillCups(vector<int>& a) {
        sort(a.begin(),a.end());
        int sum = a[0]+a[1]+a[2];
        return max(a[2], (sum+1)/2);
    }
};