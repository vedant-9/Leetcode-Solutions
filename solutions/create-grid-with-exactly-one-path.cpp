class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans(m, string(n, '#'));
        ans[0] = string(n, '.');
        for(auto &s: ans) {
            s.back() = '.';
        }
        return ans;
    }   
};
