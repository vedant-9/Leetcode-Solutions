// https://leetcode.com/problems/move-pieces-to-obtain-a-string

class Solution {
public:
    bool canChange(string s, string t) {
        int n = s.size();
        int i = 0, j = 0;
        while(i<=n and j<=n) {
            while(i<n and s[i]=='_') i++;
            while(j<n and t[j]=='_') j++;
            if(i==n or j==n) 
                return (i==n and j==n);
            if(s[i]!=t[j]) 
                return 0;
            if(s[i]=='L') {
                if(i<j) 
                    return 0;
            } else {
                if(i>j)
                    return 0;
            }
            i++;
            j++;
        }
        return 1;
    }
};