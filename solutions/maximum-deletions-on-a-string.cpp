// https://leetcode.com/problems/maximum-deletions-on-a-string

class Solution {
public:
    vector<int> z_function(string s) {
        int n = (int) s.length();
        vector<int> z(n);
        for (int i=1, l=0, r=0; i<n; ++i) {
            if (i <= r)
                z[i] = min (r-i+1, z[i-l]);
            while (i+z[i] < n && s[z[i]] == s[i+z[i]])
                ++z[i];
            if (i+z[i]-1 > r)
                l = i,  r = i+z[i]-1;
        }
        return z;
    }
    vector<int> all_prefix(string s){
        int n = s.size();
        vector<int> z = z_function(s);
        vector<int> poss;
        for(int i=1;i<n;i++){
            if(z[i]>=i) poss.push_back(i);
        }
        return poss;
    }
    int dp[4050];
    string s;
    int m;
    int rec(int sz) {
        if(sz == 0) return 0;
        if(dp[sz]!=-1) return dp[sz];
        
        int mx = 0;
        auto v = all_prefix(s.substr(m-sz));
        for(auto &x: v) {
            int y = sz-x;
            mx = max(mx, rec(y)+1);
        }
        if(v.empty()) mx = 1;
        return dp[sz] = mx;
    }
    int deleteString(string s) {
        this->s = s;
        m = s.size();
        for(int i=0; i<=m; i++) dp[i]=-1;
        return rec(m);
    }
};