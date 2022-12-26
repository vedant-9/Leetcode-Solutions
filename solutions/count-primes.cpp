// https://leetcode.com/problems/count-primes

class Solution {
public:
    
    int countPrimes(int n) 
    {
        if(n<=1)
            return 0;
        bool spf[n+1];
        memset(spf,true,sizeof(spf));

        
        for(int i=2;i*i<=n;i++)
        {
            if(spf[i])
            { 
                for(int j=i*i;j<=n;j+=i)
                {
                    spf[j] = false;
                }
            }
        }
    
        return (count(spf+2, spf+n, true));
    }
};