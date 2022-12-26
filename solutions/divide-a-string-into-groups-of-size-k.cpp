// https://leetcode.com/problems/divide-a-string-into-groups-of-size-k

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        for(int i=0;i<s.size()/k*k;i+=k) {
            ans.push_back(s.substr(i,k));
        }
        int cur = s.size()/k*k;
        string p;
        while(cur<s.size()) p+=s[cur],cur++;
        while(p.size() and p.size()<k) p+=fill;
        if(p.size()==k) ans.push_back(p);
        return ans;
    }
};