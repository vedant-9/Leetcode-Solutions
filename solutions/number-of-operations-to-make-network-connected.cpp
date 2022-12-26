// https://leetcode.com/problems/number-of-operations-to-make-network-connected

class Solution {
public:
    class dsu {
    public:
        vector<int> p,s; int comps;
        dsu(int n) {
            p.resize(n); s.resize(n); comps=n;
            for(int i=0;i<n;i++)
                p[i]=i,s[i]=1;
        }
        int find_set(int x) {
            if(p[x]==x) return x;
            return find_set(p[x]);
        }
        bool same_set(int x,int y) {
            return find_set(x)==find_set(y);
        }
        void union_sets(int x,int y) {
            x=find_set(x); y=find_set(y);
            if(x==y) return;
            if(s[x]<s[y]) swap(x,y);
            p[y]=x; s[x]+=s[y]; comps--;
        }
    };
    int makeConnected(int n, vector<vector<int>>& edges) {
        if(edges.size()<n-1) return -1;
        dsu d(n);
        for(auto e:edges) {
            d.union_sets(e[0],e[1]);
        }
        return d.comps-1;
    }
};