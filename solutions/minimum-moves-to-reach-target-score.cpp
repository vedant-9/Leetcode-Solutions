// https://leetcode.com/problems/minimum-moves-to-reach-target-score

class Solution {
public:
    int minMoves(int t, int md) {
        int ans = 0;
        while(t!=1 and md--) {
            if(t&1) ans++;
            t/=2;
            ans++;
        }
        ans+=(t-1);
        return ans;
    }
};