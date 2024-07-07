class Solution {
public:
    void rec(int n, string str, vector<string> &res) {
        if (str.length() == n) {
            res.push_back(str);
            return;
        }

        rec(n, str + "1", res);

        if (str.empty() || str.back() != '0') {
            rec(n, str + "0", res);
        }
    }

    vector<string> validStrings(int n) {
        vector<string> res;
        rec(n, "", res);
        return res;
    }
};
