// https://leetcode.com/problems/number-of-times-binary-string-is-prefix-aligned

class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int n = flips.size();
        
        int ans = 0, mx = 0;
        for(int i=0; i<n; i++) {
            mx = max(mx, flips[i]);
            if(mx == i+1) ans++;
        }
    
        return ans;
    }
};