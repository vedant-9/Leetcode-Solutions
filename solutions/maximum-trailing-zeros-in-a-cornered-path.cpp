// https://leetcode.com/problems/maximum-trailing-zeros-in-a-cornered-path

typedef long long ll;
class Solution {
public:
    int maxTrailingZeros(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        
        vector<vector<pair<ll,ll>>> g(n,vector<pair<ll,ll>>(m,{0,0}));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                int x = a[i][j];
                int c = 0;
                while(x%2==0) x/=2,c++;
                g[i][j].second = c;
                c = 0;
                while(x%5==0) x/=5,c++;
                g[i][j].first = c;
            }
        }
        
        
        vector<vector<pair<ll,ll>>> top(n,vector<pair<ll,ll>>(m,{0,0}));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(i==0) {
                    top[i][j] = g[i][j];
                } else {
                    top[i][j] = {top[i-1][j].first+g[i][j].first,top[i-1][j].second+g[i][j].second};
                }
            }
        }
        
        vector<vector<pair<ll,ll>>> left(n,vector<pair<ll,ll>>(m,{0,0}));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(j==0) {
                    left[i][j] = g[i][j];
                } else {
                    left[i][j] = {left[i][j-1].first+g[i][j].first,left[i][j-1].second+g[i][j].second};
                }
            }
        }
        
        ll ans = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                pair<ll,ll> down,right;
                down.first = top[n-1][j].first-top[i][j].first; down.second = top[n-1][j].second-top[i][j].second;
                right.first = left[i][m-1].first-left[i][j].first; right.second = left[i][m-1].second-left[i][j].second;
                
                // L shape rotate 4 times
                ans = max(ans, min(down.first+left[i][j].first, down.second+left[i][j].second));
                ans = max(ans, min(down.first+right.first+g[i][j].first,down.second+right.second+g[i][j].second));
                ans = max(ans, min(top[i][j].first+left[i][j].first-g[i][j].first, top[i][j].second+left[i][j].second-g[i][j].second));
                ans = max(ans, min(top[i][j].first+right.first, top[i][j].second+right.second));
            }
        }
        
        return ans;
    }
};