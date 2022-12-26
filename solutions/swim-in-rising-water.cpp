// https://leetcode.com/problems/swim-in-rising-water

class Solution {
public:
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    struct T {
        int t,x,y;
        T(int a, int b, int c) : t(a), x(b), y(c) {}
        bool operator<(const T &d) const { return t > d.t;}  
    };
    int swimInWater(vector<vector<int>>& a) {
        int n = a.size(), res = 0;
        vector<vector<int>> vis(n,vector<int>(n,0));
        priority_queue<T> q;
        q.push(T(a[0][0],0,0)); vis[0][0] =1;
        while(true) {
            auto p = q.top(); q.pop();
            res = max(res, p.t);
            if (p.x==n-1 && p.y==n-1) return res;
            for (auto&d:dir) {
                int i = p.x+d[0], j = p.y+d[1];
                if (i>=0 && i<n && j>=0 && j<n && !vis[i][j]) {
                    vis[i][j] = 1;
                    q.push(T(a[i][j],i,j));
                }
            }
        } 
        return res;
    }
};