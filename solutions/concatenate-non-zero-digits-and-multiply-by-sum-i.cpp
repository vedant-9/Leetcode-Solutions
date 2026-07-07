class Solution {
public:
    long long sumAndMultiply(int n) {
        long long num = 0, sum = 0;
        while (n) {
            sum += n % 10;
            if (n % 10) num = num * 10 + n % 10;
            n /= 10;
        }
        int rev = 0;
        while (num) {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        return rev * sum;
    }
};
