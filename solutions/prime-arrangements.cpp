// https://leetcode.com/problems/prime-arrangements

class Solution {
public:
    const int mod = 1e9+7;
    int numPrimeArrangements(int n) {
        int primeCount = 0;
        for(int i=2; i<=n; i++) {
            bool isPrime = true;
            for(int j=2; j*j<=i; j++) {
                if(i%j == 0) {
                    isPrime = false; 
                    break;
                }
            }
            if(isPrime) 
                primeCount++;
        }
        
        int ans = 1;
        // prime number arrangment - 
        for(int i=1; i<=primeCount; i++) 
            ans = ((long long) ans*i)%mod;
        // non-prime number arrangement - 
        for(int i=1; i<=n-primeCount; i++) 
            ans = ((long long) ans*i)%mod;
        
        return ans;
    }
};