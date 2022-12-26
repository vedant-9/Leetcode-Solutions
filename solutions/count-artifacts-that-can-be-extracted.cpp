// https://leetcode.com/problems/count-artifacts-that-can-be-extracted

class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& art, vector<vector<int>>& dig) {
        vector<vector<int>> a(n,vector<int> (n,0));
        for(auto d:dig) {
            a[d[0]][d[1]]=1;
        }
        int ans = 0;
        for(auto p:art) {
            int f=0;
            for(int i=p[0];i<=p[2];i++) {
                for(int j=p[1];j<=p[3];j++) {
                    if(a[i][j]==0) {
                        f=1; break;
                    }
                }
            }
            if(!f) ans++;
        }
        return ans;
    }
};