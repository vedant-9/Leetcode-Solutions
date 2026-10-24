class Solution {
public:
    int countMagicalPairs(string s) {
        int n = s.size();
        vector<vector<int>> pre(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            set<char> st;
            for (int j = i; j < n; j++) {
                st.insert(s[j]);
                pre[i][j] = st.size();
            }
        }
        int cnt = 0;
        for (int j = 0; j < n - 1; j++) {
            map<int, pair<int, int>> mp;
            for (int i = 0; i <= j; i++) {
                mp[pre[i][j]].first++;
                mp[pre[i][j]].second = 0;
            }
            for (int k = j + 1; k < n; k++) {
                if (mp.find(pre[j + 1][k]) == mp.end())
                    mp[pre[j + 1][k]].first = 0;
                mp[pre[j + 1][k]].second++;
            }
            for (auto [i, it] : mp) {
                cnt += it.first * it.second;
            }
        }
        return cnt;
    }
};
