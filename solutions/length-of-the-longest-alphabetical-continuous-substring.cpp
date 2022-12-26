// https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring

class Solution {
public:
    int longestContinuousSubstring(string s) {
        int i = 1, j = 0, n = s.size(), mx = 1;
        while(i < n) {
            int j = i;
            while(i < n and s[i] == s[i-1]+1) i++;
            mx = max(mx, i-j+1);
            i++;
        }
        return mx;
    }
};