// https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array

class Solution {
public:
    int dp[100005];
    bool rec(int i, vector<int> &a) {
        if(i == a.size()) return 1;
        if(dp[i]!=-1) return dp[i];
        if(i+1 < a.size() and a[i]==a[i+1] and rec(i+2,a)) return dp[i]=1;
        if(i+2 < a.size() and ((a[i]==a[i+1] and a[i]==a[i+2]) or (a[i]+1==a[i+1] and a[i+1]+1==a[i+2])) and rec(i+3,a)) return dp[i]=1;
        return dp[i]=0;
    }
    
    bool validPartition(vector<int>& a) {
        memset(dp,-1,sizeof(dp));
        return rec(0,a);
    }
};