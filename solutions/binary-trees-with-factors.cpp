// https://leetcode.com/problems/binary-trees-with-factors

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& a) {
        int n = a.size(), mod = 1e9+7;
        
        unordered_map<int,long> dp;
        sort(a.begin(),a.end());
        
        int res = 0;
        for(int i=0;i<n;i++) {
            dp[a[i]] = 1;
            for(int j=0;j<i;j++) {
                if(a[i]%a[j] == 0) {
                    dp[a[i]] = (dp[a[i]] + dp[a[j]] * dp[a[i]/a[j]])%mod;
                }
            }
            res = (res + dp[a[i]])%mod;
        }
        
        return res;
    }
};