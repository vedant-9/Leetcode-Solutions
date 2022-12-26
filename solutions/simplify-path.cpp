// https://leetcode.com/problems/simplify-path

class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        if (n == 0) return "";
        vector<string> stk;
        int i = 0;
        while (i < n) {
            while (i < n && path[i] == '/') i++;
            if (i == n) break;
            int j = i;
            while (j < n && path[j] != '/') j++;
            string s = path.substr(i, j - i);
            if (s == "..") {
                if (!stk.empty()) stk.pop_back();
            } else if (s != ".") {
                stk.push_back(s);
            }
            i = j;
        }
        string res = "";
        for (auto s : stk) {
            res += "/" + s;
        }
        if (res.empty()) return "/";
        return res;
    }
};