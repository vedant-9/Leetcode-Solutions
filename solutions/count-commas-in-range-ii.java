class Solution {
    public long countCommas(long n) {
        // 1 to 999 - 0
        // 1000 to 9999 - 1 * 9000
        // 10000 to 99999 - 1 * 90000
        // 100000 to 999999 - 1 * 900000
        // 1000000 to 9999999 - 2 * 90000000
        long tot = 0;
        for(long i = 1000, c = 3; i <= n; i *= 10, c++) {
            if(n < i * 10) tot += (c/3) * (n - i + 1);
            else tot +=  9 * (c/3) * i;
        }
        return tot;
    }
}
