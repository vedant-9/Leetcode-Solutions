// https://leetcode.com/problems/check-distances-between-same-letters

class Solution {
public:
    bool checkDistances(string s, vector<int>& d) {
        vector<int> prev(26,-1);
        for(int i=0; i<s.size(); i++) {
            if(prev[s[i]-'a'] != -1) {
                if(i-prev[s[i]-'a']-1 != d[s[i]-'a']) {
                    return 0;
                }
            }
            prev[s[i]-'a'] = i;
        }
        return 1;
    }
};