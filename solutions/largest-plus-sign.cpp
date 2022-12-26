// https://leetcode.com/problems/largest-plus-sign

class Solution {
public:
    int n;
    bool isvalid(int i, int j) { return i>=0 and j>=0 and i<n and j<n;}
    
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines)
    {
        this->n = n;
        
        vector<vector<int>> a(n,vector<int> (n,1));
        for(auto m:mines)
        {
            a[m[0]][m[1]] = 0;
        }
        
        int left[n][n], top[n][n], right[n][n], bottom[n][n];
        
        int mx = 0;
        
        // left and top 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]==0)
                    left[i][j] = 0, top[i][j] = 0;
                else
                {
                    top[i][j] = (i-1>=0)?top[i-1][j]+1:1;
                    left[i][j] = (j-1>=0)?left[i][j-1]+1:1;
                }
            }
        }
        
        // right and bottom
        for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(a[i][j]==0)
                    right[i][j] = 0, bottom[i][j] = 0;
                else
                {
                    bottom[i][j] = (i+1<n)?bottom[i+1][j]+1:1;
                    right[i][j] = (j+1<n)?right[i][j+1]+1:1;
                    mx = max(mx,min({left[i][j],right[i][j],top[i][j],bottom[i][j]}));
                }
            }
        }
    
        return mx;
    }
};