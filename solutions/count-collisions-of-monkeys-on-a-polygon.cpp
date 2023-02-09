class Solution {
public:
    const int mod = 1e9+7;
    long long expo_power(long long a, long long b) {
        long long res = 1;
        while(b) {
            if(b % 2 == 1) res = (res * a)%mod;
            a = (a * a)%mod;
            b >>= 1;
        }
        return res;
    }
    int monkeyMove(int n) {
        return (int) (expo_power(2LL, (long long) n) - 2 + mod) % mod;
    }
};
