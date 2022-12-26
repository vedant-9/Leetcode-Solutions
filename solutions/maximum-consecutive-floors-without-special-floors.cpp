// https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& a) {
        sort(a.begin(),a.end());
        int prev = bottom-1, mx = 0;
        for(auto x:a) {
            mx = max(mx, max(0,x-prev-1));
            prev = x;
        }
        mx = max(mx,max(0,top-prev));
        return mx;
    }
};