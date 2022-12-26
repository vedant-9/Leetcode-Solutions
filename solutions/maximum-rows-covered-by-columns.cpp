// https://leetcode.com/problems/maximum-rows-covered-by-columns

class Solution {
public:
    int maximumRows(vector<vector<int>>& mat, int cols) {
        int m = mat.size(), n = mat[0].size();
        int ans = 0;
        for(int i=1; i<(1<<n); i++) {
            if(__builtin_popcount(i) != cols) continue;
            vector<int> vis(n,0);
            for(int j=0; j<n; j++) {
                if(i & (1<<j)) {
                    vis[j] = 1;
                }
            }
            int here = 0;
            for(int k=0; k<m; k++) {
                int flag = 0;
                for(int l=0; l<n; l++) {
                    if(mat[k][l] == 1 and vis[l] == 0) {
                        flag = 1;
                        break;
                    }
                }   
                if(flag == 0)
                    here++;
            }
            ans = max(ans, here);
        }
        return ans;
    }
};