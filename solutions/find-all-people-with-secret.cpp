// https://leetcode.com/problems/find-all-people-with-secret

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
    vector<int> findAllPeople(int n, vector<vector<int>>& a, int fp) {
        sort(a.begin(),a.end(),[](const vector<int> &x, const vector<int> &y){
           return x[2]<y[2]; 
        });
        dsu d(n+1); d.union_sets(0,fp); 
        int m=a.size();
        for(int i=0;i<m;) {
            int t=a[i][2],j=i;
            queue<int> q;
            map<int,vector<int>> adj;
            set<int> s;
            while(i<m and a[i][2]==t) {
                if(d.same_set(a[i][0],0)) 
                    s.insert(a[i][0]);
                if(d.same_set(a[i][1],0))
                    s.insert(a[i][1]);
                adj[a[i][0]].push_back(a[i][1]);
                adj[a[i][1]].push_back(a[i][0]);
                i++;
            }
            map<int,int> vis;
            for(auto it:adj) vis[it.first]=0;
            for(auto x:s) vis[x]=1,q.push(x);
            while(!q.empty()) {
                auto cur=q.front(); q.pop();
                for(auto x:adj[cur]) {
                    d.union_sets(x,0);
                    if(!vis[x] and d.same_set(x,0)) {
                        q.push(x); vis[x]=1;
                    }
                }
            }
            
        }
        vector<int> ans; ans.push_back(0);
        for(int i=1;i<=n;i++) {
            if(d.same_set(i,0)) ans.push_back(i);
        }
        return ans;
    }
};