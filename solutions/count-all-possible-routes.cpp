class Solution {
   public:
    int MOD = 1e9 + 7;
    int memo[101][201];
    int n;

    int dfs(vector<int>& a, int finish, int cur, int cur_fuel) {
        if (cur_fuel < 0) return 0;
        if (memo[cur][cur_fuel] != -1) return memo[cur][cur_fuel];

        int ways = (cur == finish);

        if (cur_fuel > 0) {
            for (int next = 0; next < n; ++next) {
                if (next == cur) continue;
                ways = (ways + dfs(a, finish, next, cur_fuel - abs(a[cur] - a[next]))) % MOD;
            }
        }

        return memo[cur][cur_fuel] = ways;
    };

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        n = locations.size();
        memset(memo, -1, sizeof(memo));
        return dfs(locations, finish, start, fuel);
    }
};
