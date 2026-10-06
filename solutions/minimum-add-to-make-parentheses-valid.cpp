class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length(), bal = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') bal++;
            else bal--;
            if (bal < 0) ans += abs(bal), bal = 0;
        }
        ans += abs(bal);
        return ans;
    }
};
