// https://leetcode.com/problems/remove-digit-from-number-to-maximize-result

class Solution {
public:
    string removeDigit(string s, char dig) {
        string mx = "";
        for(int i=0;i<s.length();i++) {
            if(s[i]==dig) {
                string t = s.substr(0,i)+s.substr(i+1);
                if(mx=="" or t>mx) {
                    mx=t;
                }
            }
        }
        return mx;
    }
};