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

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        dsu d(n);

        unordered_map<int, unordered_set<int>> componentVertices;
        unordered_map<int, int> componentEdges;
        
        for (auto& edge : edges) {
            d.union_sets(edge[0], edge[1]);
        }

        for (int i = 0; i < n; ++i) {
            int root = d.find_set(i);
            componentVertices[root].insert(i);
        }

        for (auto& edge : edges) {
            int root = d.find_set(edge[0]);
            componentEdges[root]++;
        }

        int completeCount = 0;
        for (auto& [root, vertices] : componentVertices) {
            int numVertices = vertices.size();
            int expectedEdges = numVertices * (numVertices - 1) / 2;
            if (componentEdges[root] == expectedEdges) {
                completeCount++;
            }
        }
        
        return completeCount;
        

        return 0;
    }
};
