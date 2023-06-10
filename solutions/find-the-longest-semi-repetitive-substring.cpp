class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int mx = 0;
        for(int i = 0; i < s.size(); i++) {
            string t = "";
            for(int j = i; j < s.size(); j++) {
                t += s[j];
                int f = 0;
                for(int k = 1; k < t.size(); k++) {
                    if(t[k] == t[k-1]) f++;
                    if(f == 2) break;
                }
                if(f==2) break;
                mx = max(mx, j-i+1);
            }
        }
        return mx;
    }
};
