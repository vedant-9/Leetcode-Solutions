class Solution {
public:
    long long rec(int idx, vector<int> &power, vector<long long> &dp, vector<int> &nxt, vector<int> &cnt) {
        if(idx >= power.size()) return 0;

        long long &ans = dp[idx];
        if(ans != -1) return ans;

        // cast it
        ans = max(ans, (long long) power[idx] * cnt[idx] + rec(nxt[idx], power, dp, nxt, cnt));

        // skip it
        ans = max(ans, rec(idx+1, power, dp, nxt, cnt));

        return ans;
    }
    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(),power.end());

        // precompute nxt and cnt
        int n = power.size();
        vector<int> nxt(n), cnt(n);

        int j = 0;
        for(int i = 0; i < n; i++) {
            if(j <= i) j = i+1;
            while(j < n and power[j] <= power[i]+2) j++;
            nxt[i] = j;
        }

        cnt[n-1] = 1;
        for(int i = n-2; i >= 0; i--) {
            if(power[i] == power[i+1]) cnt[i] = cnt[i+1]+1;
            else cnt[i] = 1;
        }


        vector<long long> dp(power.size(), -1);
        return rec(0, power, dp, nxt, cnt);
    }
};
