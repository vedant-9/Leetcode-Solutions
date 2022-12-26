// https://leetcode.com/problems/largest-local-values-in-a-matrix

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& g) {
        int n = g.size();
        vector<vector<int>> ans(n-2,vector<int>(n-2));
        for(int i=0;i<=n-3;i++) {
            for(int j=0;j<=n-3;j++) {
                int mx = g[i][j];
                for(int l=i;l<i+3;l++) {
                    for(int k=j;k<j+3;k++) {
                        mx = max(mx, g[l][k]);
                    }
                }
                ans[i][j]=mx;
            }
        }
        return ans;
    }
};