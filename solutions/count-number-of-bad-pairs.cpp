// https://leetcode.com/problems/count-number-of-bad-pairs

class Solution {
public:
    long long countBadPairs(vector<int>& a) {
        long long ans = 0;
        unordered_map<int, int> m;
        for (int i=0; i<a.size(); i++) {
            ans += (i-m[a[i]-i]);
            m[a[i]-i]++;
        }
        return ans;
    }
};