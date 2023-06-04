class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long sum = 0;
        int rem_row = n, rem_col = n;
        set<int> row_vis, col_vis;
        
        for(int i = queries.size()-1; i >= 0; i--) {
            int type = queries[i][0], idx = queries[i][1], val = queries[i][2];
            
            if(!type) {
                if(row_vis.find(idx) == row_vis.end()) {
                    sum += rem_col * val;
                    row_vis.insert(idx);
                    rem_row--;
                }
            } else {
                if(col_vis.find(idx) == col_vis.end()) {
                    sum += rem_row * val;
                    col_vis.insert(idx);
                    rem_col--;
                }
            }
        }
        
        return sum;
    }
};
