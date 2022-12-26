// https://leetcode.com/problems/maximum-segment-sum-after-removals

typedef long long ll;
class Solution {
public:
    class dsu {
    public:
        vector<ll> p,s;
        dsu(ll n) {
            p.resize(n); s.resize(n);
            for(ll i=0;i<n;i++)
                p[i]=i,s[i]=1;
        }
        ll find_set(ll x) {
            if(p[x]==x) return x;
            return find_set(p[x]);
        }
        bool same_set(ll x,ll y) {
            return find_set(x)==find_set(y);
        }
        void union_sets(ll x,ll y) {
            x=find_set(x); y=find_set(y);
            if(x==y) return;
            if(s[x]<s[y]) swap(x,y);
            p[y]=x; s[x]+=s[y];
        }
    };
    
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        // use dsu for discontinuity between segments
        // size of each set -> sum of connected component segement
        // traverse backwards combining segments (finding maximum connected continious segment size (sum))
        int n = nums.size();
        
        dsu d(n);
        
        for(int i=0;i<n;i++) {
            d.s[i] = nums[i];
        }
        
        ll ans = 0;
        vector<ll> res(n);
        vector<int> used(n,0);
        
        for(int i=n-1;i>=0;i--) {
            res[i] = ans;
            int x = removeQueries[i];
            used[x] = 1;
            if(x-1>=0 and used[x-1]) d.union_sets(x-1,x);
            if(x+1<n and used[x+1]) d.union_sets(x,x+1);
            ans = max(ans, (ll)d.s[d.find_set(x)]);
        }
        
        return res;
    }
};