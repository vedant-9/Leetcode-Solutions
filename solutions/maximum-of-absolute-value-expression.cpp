class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        // The expression equals max over sign choices s1,s2 of f(i)-f(j),
        // where f(k) = s1*arr1[k] + s2*arr2[k] + k. For each fixed pattern
        // the best i,j give max(f) - min(f); 4 patterns cover all cases.
        int n = arr1.size();
        int ans = 0;
        int signs[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        for (auto& s : signs) {
            int mn = INT_MAX, mx = INT_MIN;
            for (int k = 0; k < n; k++) {
                int f = s[0] * arr1[k] + s[1] * arr2[k] + k;
                mn = min(mn, f);              // smallest f seen so far
                mx = max(mx, f);              // largest f seen so far
            }
            ans = max(ans, mx - mn);         
        }
        return ans;
    }
};
