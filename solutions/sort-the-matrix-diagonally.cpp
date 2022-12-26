// https://leetcode.com/problems/sort-the-matrix-diagonally

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        for(int i=0; i<m; i++) {
            vector<int> tmp;
            int x = i, y = 0, k = 0;
            while(x<m and y<n) {
                tmp.push_back(mat[x++][y++]);
            }
            sort(tmp.begin(), tmp.end());
            x = i, y = 0;
            while(x<m and y<n) {
                mat[x++][y++] = tmp[k++];
            }
        }
        
        for(int j=1; j<n; j++) {
            vector<int> tmp;
            int x = 0, y = j, k = 0;
            while(x<m and y<n) {
                tmp.push_back(mat[x++][y++]);
            }
            sort(tmp.begin(), tmp.end());
            x = 0, y = j;
            while(x<m and y<n) {
                mat[x++][y++] = tmp[k++];
            }
        }
        
        return mat;
    }
};