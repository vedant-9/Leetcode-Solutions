class Solution {
public:
    int rec(int idx, vector<int> &days, vector<int> &costs, vector<int> &dp) {
        int n = days.size();
        if(idx == n) return 0;

        if(dp[idx] != -1) return dp[idx];

        // take one day pass
        int ans = rec(idx+1, days, costs, dp) + costs[0];

        // take seven day pass
        int idx2 = idx;
        while(idx2 < n and days[idx2] < days[idx]+7) idx2++;
        ans = min(ans, rec(idx2, days, costs, dp) + costs[1]);

        // take thirty day pass
        int idx3 = idx;
        while(idx3 < n and days[idx3] < days[idx]+30) idx3++;
        ans = min(ans, rec(idx3, days, costs, dp) + costs[2]);

        return dp[idx] = ans; 
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, -1);
        return rec(0, days, costs, dp);
    }
};
