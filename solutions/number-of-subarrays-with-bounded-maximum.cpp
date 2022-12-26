// https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& a, int left, int right) {
        return count(a, right) - count(a, left - 1);
    }
    int count(const vector<int>& a, int bound) 
    {
        int ans = 0, cnt = 0;
        for (int x : a) 
        {
            cnt = ((x <= bound) ? cnt + 1 : 0);
            ans += cnt;
        }
        return ans;
    }
};