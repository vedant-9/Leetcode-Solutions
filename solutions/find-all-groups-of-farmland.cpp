// https://leetcode.com/problems/find-all-groups-of-farmland

class Solution {
public:
    int m,n;
    
    bool isvalid(int i, int j) { return i>=0 && j>=0 && i<m && j<n;}
    
    vector<vector<int>> findFarmland(vector<vector<int>>& a) 
    {
        m = a.size(), n = a[0].size();
        vector<vector<int>> res;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {   
                if(a[i][j]==0 or (a[i][j]==1 and vis[i][j]))
                    continue;
                vector<int> t;
                t.push_back(i);
                t.push_back(j);
                int k1 = 1,k2 = 0,f=0;
                
                while(isvalid(i+k1,j) and a[i+k1][j])
                    k1++;
                while(isvalid(i,j+k2) and a[i][j+k2])
                    k2++;

                t.push_back(i+k1-1);
                t.push_back(j+k2-1);
                res.push_back(t);
                
                for(int l = i;l<=i+k1-1;l++)
                {
                    for(int p = j;p<=j+k2-1;p++)
                    {
                        vis[l][p] = 1;
                    }
                }
            }
        }
        return res;
    }
};