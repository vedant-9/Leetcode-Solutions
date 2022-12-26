// https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks

class Solution {
public:
    int minimumRecolors(string s, int k) {
        int n = s.size(), mn = k;
        for(int i=0; i<n-k+1; i++) {
            int whiteCount = 0;
            for(int j=0; j<k; j++) {
                if(s[i+j] == 'W')
                    whiteCount++;
            }
            mn = min(mn, whiteCount);
        }
        return mn;
    }
};