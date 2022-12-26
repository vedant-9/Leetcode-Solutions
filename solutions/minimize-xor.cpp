// https://leetcode.com/problems/minimize-xor

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt = 0;
        for(int i=0; i<32; i++) {
            if(num2 & (1<<i)) cnt++;
        }
        
        // cout<<cnt<<endl;
        
        int vis[32] = {0};
        int p = num1;
        for(int i=31; i>=0; i--) {
            if(cnt == 0) break;
            if(num1 & (1<<i)) num1 &= ~(1<<i), cnt--, vis[i]=1;
        }
        
        if(cnt) {
            for(int i=0; i<32; i++) {
                if(cnt == 0) break;
                if(!vis[i]) num1 |= (1<<i), cnt--;
            }
        }
        
        return num1^p;
    }
};