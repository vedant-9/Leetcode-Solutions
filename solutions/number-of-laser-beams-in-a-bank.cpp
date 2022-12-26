// https://leetcode.com/problems/number-of-laser-beams-in-a-bank

class Solution {
public:
    int numberOfBeams(vector<string>& a) {
        int m = a.size(), n = a[0].size();
        int prev = 0, ans = 0;
        for(int i=0;i<m;i++) {
            int c = 0;
            for(int j=0;j<n;j++) {
                if(a[i][j]=='1') c++;
            }
            if(c) {
                ans += prev*c;
                prev = c;
            }
        }
        return ans;
    }
};