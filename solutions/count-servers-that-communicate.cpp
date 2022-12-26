// https://leetcode.com/problems/count-servers-that-communicate

class Solution {
public:
    int countServers(vector<vector<int>>& a) {
        int m = a.size(), n = a[0].size(), ans = 0;
        
        for(int i=0;i<m;i++) 
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]==1) {
                    
                    int f1=0,f2=0;
                    for(int k=0;k<n;k++)
                    {
                        if(a[i][k]==1 and k!=j) f1=1;
                    }
                    for(int l=0;l<m;l++) 
                    {
                        if(a[l][j]==1 and l!=i) f2=1;
                    }
                    
                    if(f1==1 or f2==1) ans++;
                }
            }
        }
        
        return ans;
    }
};