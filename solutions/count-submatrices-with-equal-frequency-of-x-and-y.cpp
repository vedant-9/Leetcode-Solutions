class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> prefixSumX(rows, vector<int>(cols, 0));
        vector<vector<int>> prefixSumY(rows, vector<int>(cols, 0));
        int ans = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                prefixSumX[i][j] = (grid[i][j] == 'X');
                prefixSumY[i][j] = (grid[i][j] == 'Y');


                if (i > 0) {
                    prefixSumX[i][j] += prefixSumX[i - 1][j];
                    prefixSumY[i][j] += prefixSumY[i - 1][j];

                }

                if (j > 0) {
                    prefixSumX[i][j] += prefixSumX[i][j - 1];
                    prefixSumY[i][j] += prefixSumY[i][j - 1];

                }

                if (i > 0 && j > 0) {
                    prefixSumX[i][j] -= prefixSumX[i - 1][j - 1];
                    prefixSumY[i][j] -= prefixSumY[i - 1][j - 1];
                }
                
                // cout<<prefixSumX[i][j]<<endl;
                
                if(prefixSumX[i][j] == prefixSumY[i][j] and prefixSumX[i][j] > 0) ans++; 
            }
        }
        
        return ans;
    }
};
