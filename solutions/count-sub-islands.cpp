// https://leetcode.com/problems/count-sub-islands

class Solution {
public:
    int n,m;
    int rec(int i,int j,vector<vector<int>>& grid1,vector<vector<int>>& grid2,vector<vector<int>> &vis1,vector<vector<int>> &vis2)
    {
        if(i<0||i>=n||j<0||j>=m)
            return 0;
        if(grid2[i][j]==1 && grid1[i][j]==0)
            return -1;
        if(grid2[i][j]==0||vis2[i][j]==1 || vis1[i][j]==1 || grid1[i][j]==0)
            return 0;
        
        
        vis2[i][j] = 1;
        vis1[i][j] = 1;
        
        int a,b,c,d;
        a= rec(i-1,j,grid1,grid2,vis1,vis2);
        b = rec(i+1,j,grid1,grid2,vis1,vis2);
        c = rec(i,j-1,grid1,grid2,vis1,vis2);
        d = rec(i,j+1,grid1,grid2,vis1,vis2);
       
        if(a==-1 || b==-1 || c==-1 || d==-1)
            return -1;
        return 1;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) 
    {
        int ans=0;
        n = grid1.size();
        m = grid1[0].size();
        vector<vector<int>> vis1(n,vector<int> (m,0));
        vector<vector<int>> vis2(n,vector<int> (m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid1[i][j]==1 && vis1[i][j]==0 && grid2[i][j]==1 && vis2[i][j]==0)
                {
                    if(rec(i,j,grid1,grid2,vis1,vis2)!=-1)
                        ans++;
                }
            }
        }
        
        return  ans;
    }
};