// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column

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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        dsu d(n);
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1]) {
                    d.union_sets(i, j);
                }
            }
        }
        return n-d.comps;
    }
};