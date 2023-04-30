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
    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), [](const auto &x, const auto &y) {
            return x[0] > y[0];
        });

        dsu d1(n), d2(n);

        int numOfEdges = 0;
        for(auto &e: edges) {
            e[1]--, e[2]--;
            if(e[0] == 3) {
                if(d1.same_set(e[1], e[2]) and d2.same_set(e[1], e[2])) continue;
                numOfEdges++;
                d1.union_sets(e[1], e[2]);
                d2.union_sets(e[1], e[2]); 
            } else if(e[0] == 1) {
                if(d1.same_set(e[1], e[2])) continue;
                d1.union_sets(e[1], e[2]);
                numOfEdges++;
            } else {
                if(d2.same_set(e[1], e[2])) continue;
                d2.union_sets(e[1], e[2]);
                numOfEdges++;
            }
        }

        return (d1.comps + d2.comps == 2) ? edges.size() - numOfEdges : -1;
    }
};
