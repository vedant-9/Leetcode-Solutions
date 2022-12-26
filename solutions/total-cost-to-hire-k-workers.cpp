// https://leetcode.com/problems/total-cost-to-hire-k-workers

typedef long long ll;

class Solution {
public:
    template<typename T>
    class segtree{
    public:
        ll size;
        vector<T> sums;
        T NEUTRAL_ELEMENT = 1e18;
        T merge(T a, T b){
            return min(a,b);
        }
        T single(ll v){
            return v;
        }
        void init(ll n){
            size = 1;
            while(size<n) size*=2;
            sums.assign(2*size,0LL);
        }
        void build(vector<int> &a, ll x, ll lx, ll rx){
            if(rx-lx==1){
                if(lx<(ll)a.size()) sums[x] = single(a[lx]);
                return;
            }
            ll m = (lx+rx)/2;
            build(a,2*x+1,lx,m);
            build(a,2*x+2,m,rx);
            sums[x] = merge(sums[2*x+1],sums[2*x+2]);
        }
        void build(vector<int> &a){
            build(a,0,0,size);
        }
        void update(ll i, T v, ll x, ll lx, ll rx){
            if(rx-lx==1){
                sums[x] = single(v);
                return;
            }
            ll m = (lx+rx)/2;
            if(i<m) update(i,v,2*x+1,lx,m);
            else update(i,v,2*x+2,m,rx);
            sums[x] = merge(sums[2*x+1],sums[2*x+2]);
        }
        void update(ll i, T v){
            update(i,v,0,0,size);
        }
        T query(ll l, ll r, ll x, ll lx, ll rx){
            if(lx>=r || l>=rx) return NEUTRAL_ELEMENT;
            if(lx>=l && rx<=r) return sums[x];
            ll m = (lx+rx)/2;
            T s1 = query(l,r,2*x+1,lx,m);
            T s2 = query(l,r,2*x+2,m,rx);
            return merge(s1,s2);
        }
        T query(ll l, ll r){
            return query(l,r+1,0,0,size);
        }
    };
    
    
    long long totalCost(vector<int>& costs, int k, int l) {
        int n = costs.size();
        
        segtree<ll> st;
        st.init(n);
        st.build(costs);
        
        map<int, deque<int>> ind;
        for(int i=0; i<n; i++) ind[costs[i]].push_back(i);
        
        ll ans = 0;
        int c1 = 0, c2 = 0;
        while(k) {
            if(l-1+c1 >= n-l-c2) break;
            ll mn1 = st.query(0, l-1+c1);
            ll mn2 = st.query(n-l-c2, n-1);
            cout<<min(mn1,mn2)<<endl;
            if(mn1 <= mn2) {
                ans += mn1;
                st.update(ind[mn1][0], 1e18);
                ind[mn1].pop_front();
                c1++;
            } else {
                ans += mn2;
                auto &v = ind[mn2];
                auto idx = lower_bound(v.begin(), v.end(), n-l-c2);
                st.update(*idx, 1e18);
                ind[mn2].erase(idx);
                c2++;
            }
            k--;
        }
        
        while(k--) {
            ll mn = st.query(0, n-1);
            ans += mn;
            st.update(ind[mn][0], 1e18);
            ind[mn].pop_front();
        }
        
        return ans;
    }
};