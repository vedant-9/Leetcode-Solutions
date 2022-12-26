// https://leetcode.com/problems/equal-row-and-column-pairs

class Solution {
public:
    int equalPairs(vector<vector<int>>& a) {
        int n = a.size(), ans = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                int f = 0;
                for(int k=0;k<n;k++) {
                    if(a[i][k]!=a[k][j]) {
                        f=1;
                        break;
                    }
                }
                if(f==0) ans++; 
            }
        }
        return ans;
    }
};