// https://leetcode.com/problems/count-prefixes-of-a-given-string

class Solution {
public:
    int countPrefixes(vector<string>& a, string s) {
        int ans = 0;
        for(auto t:a) {
            if(s.substr(0,t.length())==t) {
                ans++;
            }
        }
        return ans;
    }
};