// https://leetcode.com/problems/largest-component-size-by-common-factor

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
    int largestComponentSize(vector<int>& a) {
        int n=*max_element(a.begin(),a.end()); 
        dsu d(n+1);
        for(auto x:a) {
            for(int k=2;k<=sqrt(x);k++) {
                if(x%k==0) {
                    d.union_sets(k,x);
                    d.union_sets(k,x/k);
                }
            }   
        }
        map<int,int> mp;
        int ans=1;
        for(auto x:a) {
            ans=max(ans,++mp[d.find_set(x)]);
        }
        return ans;
    }
};