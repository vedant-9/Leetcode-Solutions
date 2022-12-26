// https://leetcode.com/problems/out-of-boundary-paths

class Solution {
public:
    const int M = 1e9+7;
    int m,n;
    int dp[51][51][51];
    int dir[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
    
    int dfs(int i, int j, int k) {
        if(i<0 or j<0 or i>=m or j>=n) return 1;
        if(k<=0) return 0;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int tot = 0;
        for(auto d:dir) {
            tot = (tot + dfs(i+d[0],j+d[1],k-1))%M;
        }
        return dp[i][j][k]=tot;
    }
    
    int findPaths(int m, int n, int k, int sr, int sc) {
        this->m = m; this->n = n; 
        memset(dp,-1,sizeof(dp));
        return dfs(sr,sc,k);
    }
};