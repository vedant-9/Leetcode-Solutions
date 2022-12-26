// https://leetcode.com/problems/k-highest-ranked-items-within-a-price-range

int lo,hi,m,n;
vector<vector<int>> a;
class Solution {
public:
    
    struct point {

        int x;
        int y;
        int d;

        point(int x, int y, int d)
        {
            this->x=x; this->y=y; this->d=d;
        }
    };
    
    static bool valid(point p) { return (lo<=a[p.x][p.y] and a[p.x][p.y]<=hi);}
    
    struct cc {
        bool operator()(point const& p1, point const& p2)
        {
            if(p1.d==p2.d) {
                if(valid(p1) and valid(p2)) {
                    if(a[p1.x][p1.y]==a[p2.x][p2.y]) {
                        if(p1.x==p2.x) return p1.y>p2.y;
                        return p1.x>p2.x;
                    } 
                    return a[p1.x][p1.y]>a[p2.x][p2.y];
                } 
                else if(valid(p1)) return 1;
                else if(valid(p2)) return 0;
                else return 0;
            } else {
                return p1.d>p2.d;
            }
    
        }  
    };
    
    int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
    
    int within(int x,int y) { return (x>=0 and y>=0 and x<m and y<n and a[x][y]!=0);}
    
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& aa, vector<int>& p, vector<int>& st, int k) {
        m = aa.size(), n = aa[0].size();
        a = aa;
        lo = p[0], hi = p[1];
        
        priority_queue<point,vector<point>,cc> pq;
        vector<vector<int>> vis(m,vector<int>(n,0));
        point pp(st[0],st[1],0);
        pq.push(pp);
        vis[st[0]][st[1]]=1;
        
        
        vector<vector<int>> ans;
        while(!pq.empty() and ans.size()<k) {
            auto cur=pq.top(); pq.pop();
            if(valid(cur)) ans.push_back({cur.x,cur.y});
            for(auto d:dir) {
                int nx=cur.x+d[0];
                int ny=cur.y+d[1];
                if(within(nx,ny) and !vis[nx][ny]) {
                    point t(nx,ny,cur.d+1);
                    pq.push(t);
                    vis[nx][ny]=1;
                } 
            }
        }
        return ans;
    }
};