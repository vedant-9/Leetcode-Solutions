class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int mxi = 0, mx = 0;
        for(int i = 0; i < mat.size(); i++) {
            int cnt = 0;
            for(auto x: mat[i]) if(x==1) cnt++;
            if(cnt > mx) {
                mxi = i; mx = cnt;
            }
        }
        return {mxi, mx};
    }
};
