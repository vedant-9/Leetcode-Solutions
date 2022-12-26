// https://leetcode.com/problems/solving-questions-with-brainpower

class Solution {
public:
    typedef long long ll;
    vector<vector<int>> a;
    ll dp[100005];
    
    ll rec(int idx) {
        if(idx>=a.size()) return 0;
        ll &ans = dp[idx];
        if(ans!=-1) return ans; 
        
        // take idx
        ans=rec(idx+a[idx][1]+1)+a[idx][0];
        
        // dont take idx
        ans=max(ans,rec(idx+1));
        
        return ans;
    }
    
    long long mostPoints(vector<vector<int>>& a) {
        this->a=a;
        memset(dp,-1,sizeof(dp));
        return rec(0);
    }
};