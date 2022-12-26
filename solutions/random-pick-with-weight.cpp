// https://leetcode.com/problems/random-pick-with-weight

class Solution {
public:
    vector<int> s;
    Solution(vector<int> w) {
        for (int i : w) {
            if(s.empty()) s.push_back(i);
            else s.push_back(s.back()+i);
        }
    }
    
    int pickIndex() {
        int m = s.back();
        int r = rand() % m;
        auto it = upper_bound(s.begin(), s.end(), r);
        return it - s.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */