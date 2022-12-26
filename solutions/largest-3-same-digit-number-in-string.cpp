// https://leetcode.com/problems/largest-3-same-digit-number-in-string

class Solution {
public:
    string largestGoodInteger(string s) {
        string mx = "";
        for(int i=0;i<=s.length()-3;i++) {
            string t = s.substr(i,3);
            if(t[0]!=t[1] or t[0]!=t[2]) continue;
            if(mx=="" or t>mx) {
                mx=t;
            }
        }
        return mx;
    }
};