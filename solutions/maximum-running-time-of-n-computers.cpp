// https://leetcode.com/problems/maximum-running-time-of-n-computers

class Solution {
public:
    long long maxRunTime(int n, vector<int>& bat) {
        long long l = 0, r = accumulate(begin(bat), end(bat), 0LL) / n;
        while (l < r) {
            long long m = (l + r + 1) / 2, minutes = 0;
            for (int b : bat)
                minutes += min((long long)b, m);
            if (minutes >= n * m)
                l = m;
            else
                r = m - 1;
        }
        return l;
    }
};