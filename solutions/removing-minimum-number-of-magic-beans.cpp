// https://leetcode.com/problems/removing-minimum-number-of-magic-beans

class Solution {
public:
    long long minimumRemoval(vector<int>& a) {
        long n = a.size(), ans = LLONG_MAX, sum = accumulate(begin(a), end(a), 0L);
        sort(begin(a), end(a));
        for (int i = 0; i < n; ++i) 
            ans = min(ans, sum - (n - i) * a[i]);
        return ans;
    }
};