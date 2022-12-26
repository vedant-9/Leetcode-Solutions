// https://leetcode.com/problems/count-asterisks

class Solution {
public:
    int countAsterisks(string s) {
        int i=0,n=s.size(),ans=0;
        while(i<n and s[i]!='|') {
            if(s[i]=='*') ans++;
            i++;
        }
        while(i<n) {
            i++;
            while(i<n and s[i]!='|') i++;
            i++;
            while(i<n and s[i]!='|') {
                if(s[i]=='*') ans++;
                i++;
            }
        }
        return ans;
    }
};