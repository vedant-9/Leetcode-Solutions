class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for(int i = 30; i >= 0; i--) {
            int as = a & (1<<i), bs = b & (1<<i), cs = c & (1<<i);
            if((as | bs) != cs) {
                if(cs) {
                    ans++;
                } else {
                    if(as) ans++;
                    if(bs) ans++;
                }
            }
        }
        return ans;
    }
};
