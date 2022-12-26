// https://leetcode.com/problems/n-queens

class Solution {
public:
    int n;
    vector<vector<string>> ans;
    
    bool valid(vector<string> &a, int row, int col) {
        //check if the column had a queen before.
        for (int i = 0; i != row; ++i)
            if (a[i][col] == 'Q')
                return false;
        //check if the 45° diagonal had a queen before.
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
            if (a[i][j] == 'Q')
                return false;
        //check if the 135° diagonal had a queen before.
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
            if (a[i][j] == 'Q')
                return false;
        return true;
    }
    
    void rec(vector<string> &a, int row) {
        if(row==n) {
            ans.push_back(a);
            return;
        }
        for(int col=0;col<n;col++) {
            if(valid(a,row,col)) {
                a[row][col] = 'Q';
                rec(a,row+1);
                a[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> a;
        for(int i=0;i<n;i++) 
            a.push_back(string(n,'.'));
        this->n = n;
        
        rec(a,0);
        
        return ans;
    }
};