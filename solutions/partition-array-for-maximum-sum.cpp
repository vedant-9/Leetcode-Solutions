class Solution {
public:
    int n;
    int rec(int i, vector<int> &arr, int k, vector<int> &dp) {
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = 0, cur_mx = 0;
        for(int j = i; j < min(i+k, n); j++) {
            cur_mx = max(cur_mx, arr[j]);
            ans = max(ans, rec(j+1, arr, k, dp) + cur_mx * (j-i+1));
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        vector<int> dp(n, -1);
        return rec(0, arr, k, dp);
    }
};
