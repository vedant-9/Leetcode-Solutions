// https://leetcode.com/problems/redundant-connection

class Solution {
public:
    class dsu {
    public:
        vector<int> p,s;
        dsu(int n) {
            p.resize(n); s.resize(n);
            for(int i=0;i<n;i++)
                p[i] = i,s[i] = 1;
        }
        int find_set(int x) {
            if(p[x]==x) return x;
            return find_set(p[x]);
        }
        bool same_set(int x, int y) {
            return find_set(x)==find_set(y);
        }
        void union_sets(int x, int y) {
            x = find_set(x); y = find_set(y);
            if(x==y) return;
            if(s[x]<s[y]) swap(x,y);
            p[y] = x; s[x] += s[y];
        }
    };
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size(); dsu d(n);
        for(auto e:edges) {
            if(d.same_set(e[0]-1,e[1]-1))
                return e;
            d.union_sets(e[0]-1,e[1]-1);
        }
        return {};
    }
};