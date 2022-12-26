// https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities

class Solution {
public:
    class dsu {
    public:
        vector<int> par,sz;
        int comps;
        dsu(int n) {
            par.resize(n); sz.resize(n); comps=n;
            for(int i=0;i<n;i++)
                par[i]=i,sz[i]=1;
        }
        int find_set(int x) {
            if(par[x]==x) return x;
            return find_set(par[x]);
        }
        bool same_set(int x,int y) {
            return find_set(x)==find_set(y);
        }
        void union_sets(int x,int y) {
            x=find_set(x); y=find_set(y);
            if(x==y) return;
            if(sz[x]<sz[y]) swap(x,y);
            par[y]=x; sz[x]+=sz[y]; comps--;
        }
    };
    
    int minScore(int n, vector<vector<int>>& roads) {
        dsu d(n);
        for(auto e: roads) {
            d.union_sets(e[0]-1,e[1]-1);
        }
        int mn = 1e9;
        for(auto e: roads) {
            if(d.same_set(0, e[0]-1) or d.same_set(0, e[1]-1)) 
                mn = min(mn, e[2]);
        }
        return mn;
    }
};