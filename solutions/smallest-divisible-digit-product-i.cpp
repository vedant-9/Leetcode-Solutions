class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int num = n; ; ++num) {
            int product = 1;
            for (int x = num; x > 0; x /= 10) {
                product *= x % 10;
            }
            if (product % t == 0) {
                return num;
            }
        }
    }
};
