class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        // merge intervals 
        sort(ranges.begin(), ranges.end());
        long long ans = 2, mod = 1e9+7;
        int prev = ranges[0][1];
        int n = ranges.size();
        for(int i = 1; i < n; i++) {
            if(ranges[i][0] <= prev) prev = max(prev, ranges[i][1]);
            else {
                prev = ranges[i][1];
                ans = (ans*2)%mod;
            }
        }
        return ans;
    }
};
