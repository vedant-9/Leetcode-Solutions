// https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor

class Solution {
public:
    const int mod = 1e9+7;
    int numberOfWays(string corridor) {
        
        // count total number of seats
        int seatCount = 0;
        for(auto ch: corridor) {
            if(ch == 'S') {
                seatCount++;
            }
        }
        
        // check if any group can have odd seats
        if(seatCount==0 or seatCount%2 != 0) {
            return 0;
        }
        
        int i = 0, sz = corridor.size(), ans = 1;
        while(i < sz) {
            int cnt = 0;
            while(i < sz and cnt < 2) {
                if(corridor[i] == 'S') 
                        cnt++;
                i++;
            }
            int plantCount = 1;
            while(i < sz and corridor[i] == 'P') {
                plantCount++;
                i++;
            }
            
            // exclude last plants
            if(i != sz)
                ans = ((long) ans * plantCount)%mod;
        }
        
        return ans;
    }
};