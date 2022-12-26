// https://leetcode.com/problems/shortest-path-in-binary-matrix

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& a) 
    {
        // simple bfs
        int n = a.size();
        if(n==0 or a[0][0]!=0 or a[n-1][n-1]!=0)
            return -1;
        queue<pair<int, int>> q;
        q.push({0,0});
        vector<vector<int>> dir = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
        a[0][0] = 1;
        
        while(!q.empty())
        {
            auto cur = q.front();
            q.pop();
            int x = cur.first, y = cur.second;
            
            if(x == n -1 && y == n -1) 
                return a[x][y];

            for(auto d : dir)
            {
                int nx = x + d[0];
                int ny = y + d[1];
                
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && a[nx][ny] == 0)
                {
                    q.push({nx,ny});
                    a[nx][ny] = a[x][y] + 1;
                }
            }
        }
        return -1;
    }
};