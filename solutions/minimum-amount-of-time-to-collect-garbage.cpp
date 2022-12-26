// https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage

class Solution {
public:
    int garbageCollection(vector<string>& a, vector<int>& t) {
        int ans = 0, n = a.size();
        for(auto &s: a) ans += s.length();
        int x = -1, y = -1, z = -1;
        for(int i=n-1; i>=1; i--) {
            string s = a[i];
            if(x==-1 and s.find('M')!=string::npos) x = i-1;
            if(y==-1 and s.find('P')!=string::npos) y = i-1;
            if(z==-1 and s.find('G')!=string::npos) z = i-1;
        }
        for(int i=1;i<n-1;i++) t[i]+=t[i-1];
        if(x!=-1) ans+=t[x];
        if(y!=-1) ans+=t[y];
        if(z!=-1) ans+=t[z];
        return ans;
    }
};