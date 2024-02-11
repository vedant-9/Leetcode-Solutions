class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(); 
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == -1) {
                    for(int k = 0; k < m; k++) {
                        mat[i][j] = max(mat[i][j], mat[k][j]);    
                    }
                }
            }
        }
        return mat;
    }
};
