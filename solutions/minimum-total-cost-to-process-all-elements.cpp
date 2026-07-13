class Solution {
public:
    int minimumCost(vector<int>& nums, int tk) {
        long long cost = 0, fac = 1, k = tk;
        const long long mod = 1e9 + 7;

        for (int x : nums) {
            if (k >= x) {
                k -= x;
                continue;
            }

            long long need = x - k;
            long long ops = (need + tk - 1LL) / tk;

            long long rem = need % tk;
            k = (rem == 0 ? 0 : tk - rem);

            long long a = ops, b = ops - 1;
            if (a & 1) b /= 2;
            else a /= 2;

            cost = (cost + ((fac % mod) * (ops % mod)) % mod) % mod;
            cost = (cost + ((a % mod) * (b % mod)) % mod) % mod;

            fac += ops;
        }

        return (int)cost;
    }
};
