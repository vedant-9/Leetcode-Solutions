// https://leetcode.com/problems/time-needed-to-rearrange-a-binary-string

class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int seconds = 0, n = s.size();
        while(1) {
            bool flag = 0;
            string t = s;
            for(int i=0; i<n-1; i++) {
                if(s[i]=='0' and s[i+1]=='1') {
                    swap(t[i], t[i+1]);
                    flag = 1;
                }
            }
            if(flag == 0)
                break;
            s = t;
            seconds++;
        }
        return seconds;
    }
};