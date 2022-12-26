// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze

class Solution {
public:
    int nearestExit(vector<vector<char>>& a, vector<int>& p) 
    {
        int m = a.size(), n = a[0].size(), ans = 1;
        
        queue<pair<int,int>> q;
        q.push({p[0],p[1]});
        a[p[0]][p[1]] = '+';
        
        int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
        
        while(!q.empty())
        {
            int k = q.size();
            while(k--)
            {
                auto [i,j] = q.front();
                q.pop();

                for(auto d:dir)
                {
                    int x = i+d[0];
                    int y = j+d[1];

                    if(x<0 or y<0 or x>=m or y>=n or a[x][y]!='.')
                        continue;

                    if(x==0 or y==0 or x==m-1 or y==n-1)
                        return ans;
                    
                    a[x][y] = '+';
                    q.push({x,y});
                }
            }
            ans++;
        }
        return -1;
    }
};