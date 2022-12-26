// https://leetcode.com/problems/count-collisions-on-a-road

class Solution {
public:
    int countCollisions(string s) {
        int n = s.size();
        int r = 0, ans = 0;
        for(int i=0;i<n;i++) {
            if(s[i]=='R') r++;
            else if(s[i]=='L') {
                if(r) ans+=(r+1);
                r=0;
            } else {
                if(r) ans+=r;
                r=0;
            }
        }
        int l=0;
        for(int i=n-1;i>=0;i--) {
            if(s[i]=='L') l++;
            else if(s[i]=='R') {
                if(l) ans+=(l-1);
                l=0;
            } else {
                if(l) ans+=l;
                l=0;
            }
        }
        return ans;
    }
};