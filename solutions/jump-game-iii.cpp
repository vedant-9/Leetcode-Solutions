// https://leetcode.com/problems/jump-game-iii

class Solution {
public:
    unordered_set<int> vis;
    bool canReach(vector<int>& a, int st) {
        if (st >= 0 && st < a.size() && vis.insert(st).second) {
            return a[st] == 0 || canReach(a, st + a[st]) || canReach(a, st - a[st]);
        }
        return false;
    }
};