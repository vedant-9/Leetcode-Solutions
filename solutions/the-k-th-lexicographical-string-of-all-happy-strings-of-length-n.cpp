class Solution {
public:
    void solve(vector<string>& ans, string& cur, int n, int& k, vector<char>& v) {
        if (ans.size() == k) return;
        if (cur.size() == n) {
            ans.push_back(cur);
            return;
        }
        for (int i = 0; i < 3; i++) {
            if (cur.size() == 0 || cur[cur.size() - 1] != v[i]) {
                cur += v[i];
                solve(ans, cur, n, k, v);
                cur.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        string cur = "";
        vector<string> ans;
        vector<char> v = {'a', 'b', 'c'};

        solve(ans, cur, n, k, v);

        return (ans.size() == k) ? ans.back() : "";
    }
};
