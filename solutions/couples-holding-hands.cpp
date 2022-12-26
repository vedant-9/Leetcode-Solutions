// https://leetcode.com/problems/couples-holding-hands

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
    int minSwapsCouples(vector<int>& a) {
        int n = a.size(), ans = 0; 
        if(n==0) return 0;
        dsu d(n);
        for(int i=0;i<n;i+=2) {
            d.p[a[i+1]] = a[i];
        }
        for(int i=0;i<n;i+=2) {
            if(!d.same_set(i,i+1))
                ans++;
            d.union_sets(i,i+1);
        }
        return ans;
    }
};