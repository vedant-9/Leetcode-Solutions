// https://leetcode.com/problems/number-of-people-aware-of-a-secret

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> vec(n+1);           
        vec[0] = 0;
        vec[1] = 1;
        int mod = 1e9+7;
        
        for(int i =1;i<=delay;i++) 
            vec[i] = 1;  
        
        for(int i = delay+1;i<=n;i++) {
            for(int j = delay;j<forget ;j++) {    
                if(i-j<=0)
                    break;
                vec[i] =(vec[i]%mod + vec[i-j]%mod)%mod;
            }
            vec[i]++;
            
            if(i-forget>=1)
                vec[i]--;
        }
        
        return vec[n];
    }
};