// https://leetcode.com/problems/number-of-equivalent-domino-pairs

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>, int> count;
        int res = 0;
        for (auto& d : dominoes) {
            if(d[0] > d[1]) swap(d[0], d[1]);
            res += count[{d[0], d[1]}]++;
        }
        return res;
    }
};