// https://leetcode.com/problems/range-product-queries-of-powers

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int mod = 1e9+7;
        bitset<32> b(n);
        vector<int> p, ans;
        for(int i=0; i<32; i++) {
            if(b[i]) p.push_back((1<<i));
        }
        for(auto &q: queries) {
            long res = 1;
            for(int i=q[0]; i<=q[1]; i++) {
                res = ((long)(res * p[i]))%mod;
            }
            ans.push_back(res);
        }
        return ans;
    }
};