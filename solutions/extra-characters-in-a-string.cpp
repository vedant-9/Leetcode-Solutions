class Solution {
public:
    int dp[51][51];
    int rec(int i, int prev, string &s, set<string> &dict) {
        if(i >= s.size()) return i-prev;
        if(dp[i][prev] != -1) return dp[i][prev];
        int ans = rec(i+1, prev, s, dict);
        ans = min(ans, rec(i+1, i+1, s, dict) + (dict.find(s.substr(prev, i-prev+1)) != dict.end() ? 0: i-prev+1));
        return dp[i][prev] = ans;
    }
    int minExtraChar(string s, vector<string> &dictionary) {
        set<string> dict;
        for(auto x: dictionary) dict.insert(x);
        memset(dp, -1, sizeof(dp));
        return rec(0, 0, s, dict);
    }
};
