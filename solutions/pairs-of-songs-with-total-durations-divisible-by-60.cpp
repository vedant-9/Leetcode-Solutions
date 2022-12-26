// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& a) {
        int res=0;
        vector<int> m(60);
        for (auto t : a) {
            res += m[(60 - t % 60) % 60];
            ++m[t % 60];
        }
        return res;
    }
};